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
# Options
#---------------------------------------------------------------------------------------
option(WITH_TESTS "Build test suite in default target" OFF)

#---------------------------------------------------------------------------------------
# Find packages
#---------------------------------------------------------------------------------------
# Extra cmake helpers
find_package(ECM REQUIRED NO_MODULE)
list(APPEND CMAKE_MODULE_PATH ${ECM_MODULE_PATH})
include(KDECompilerSettings NO_POLICY_SCOPE)
include(KDEInstallDirs)
include(KDECMakeSettings)
include(ECMQtDeclareLoggingCategory)
include(ECMInstallIcons)

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

# Bundled thirdparty code
add_subdirectory(thirdparty)

add_feature_info(Tests WITH_TESTS "build unit tests")
feature_summary(INCLUDE_QUIET_PACKAGES FATAL_ON_MISSING_REQUIRED_PACKAGES WHAT ALL)

#---------------------------------------------------------------------------------------
# Set compiler options and detect features
#---------------------------------------------------------------------------------------
# Only set compile options after any inclusion of third party code
include(cmake/CompileOptions.cmake)

add_subdirectory(src)

if(WITH_TESTS)
    add_subdirectory(tests)
endif(WITH_TESTS)
