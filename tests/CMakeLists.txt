set(unittest_SRCS
    test_spotlightparser
)

set(unittest_LIBRARIES
    spotlightprovider_static
)

# The Catch2 test runner
add_executable(unittests main.cpp ${unittest_SRCS})
target_link_libraries(unittests
    Catch2::Catch2
    ${unittest_LIBRARIES}
)
catch_discover_tests(unittests)
