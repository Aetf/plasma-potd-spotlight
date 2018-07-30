set(unittest_SRCS
    test_spotlightparser.cpp
    test_spotlightprovider.cpp
)

set(unittest_LIBRARIES
    spotlightprovider_static
    Qt5::Test
)

# The Catch2 test runner
add_executable(unittests main.cpp ${unittest_SRCS})
target_link_libraries(unittests
    Catch2::Catch2
    ${unittest_LIBRARIES}
)
catch_discover_tests(unittests)
