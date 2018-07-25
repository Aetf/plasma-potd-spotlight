cmake_minimum_required(VERSION 3.11)

project(plasma_potd_spotlight LANGUAGES C CXX)
set(PROJECT_VERSION "1.0.0")
set(PROJECT_VERSION_MAJOR 1)

#---------------------------------------------------------------------------------------
# Initial setups
#---------------------------------------------------------------------------------------
# Include utilities
include(cmake/Utilities.cmake)
list(APPEND CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)
# For feature_summary
include(FeatureSummary)

# Setup defaults
include(cmake/Defaults.cmake)
# Extra build types
include(cmake/BuildTypes.cmake)

#---------------------------------------------------------------------------------------
# Find packages
#---------------------------------------------------------------------------------------
# Extra cmake helpers
find_package(ECM ${KF5_MIN_VERSION} REQUIRED NO_MODULE)
set(CMAKE_MODULE_PATH ${ECM_MODULE_PATH})
include(KDEInstallDirs)
include(KDECMakeSettings)
include(KDECompilerSettings NO_POLICY_SCOPE)
include(ECMQtDeclareLoggingCategory)
include(ECMInstallIcons)
include(KDEPackageAppTemplates)
include(GenerateExportHeader)
include(CMakePackageConfigHelpers)

# For Plasma::PotdProvider
find_package(PlasmaPotdProvider REQUIRED)
set_package_properties(PlasmaPotdProvider PROPERTIES TYPE REQUIRED PURPOSE
    "For core Plasma potd library"
)

find_package(Qt5 5.10 CONFIG REQUIRED COMPONENTS
    Core
    Gui
)

find_package(KF5 REQUIRED COMPONENTS
    KIO
)

feature_summary(INCLUDE_QUIET_PACKAGES FATAL_ON_MISSING_REQUIRED_PACKAGES WHAT ALL)

#---------------------------------------------------------------------------------------
# Set compiler options and detect features
#---------------------------------------------------------------------------------------
# Only set compile options after any inclusion of third party code
include(cmake/CompileOptions.cmake)

add_subdirectory(src)
