# Library name, also the path
set(library_name Catch2)

# Set any options
#set(SPDLOG_BUILD_TESTING OFF CACHE BOOL "Build spdlog tests" FORCE)
set(CATCH_INSTALL_DOCS OFF CACHE BOOL "" FORCE)
set(CATCH_INSTALL_HELPERS OFF CACHE BOOL "" FORCE)
set(CATCH_BUILD_TESTING OFF CACHE BOOL "" FORCE)
set(CATCH_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

add_submodule(${library_name})

include(CTest)
include(${library_name}/contrib/Catch.cmake)
# Fix No cmake script provided error when calling catch2_discover_tests
# by setting the variable in parent scope
set(_CATCH_DISCOVER_TESTS_SCRIPT ${CMAKE_CURRENT_LIST_DIR}/${library_name}/contrib/CatchAddTests.cmake PARENT_SCOPE)
