add_executable(LibTest 
    tests/dummy_test.cpp
    tests/fractalDimensionTest.cpp
)

target_link_libraries(LibTest
    PRIVATE
        Library
        gtest_main
)

enable_testing()
include(GoogleTest)
gtest_discover_tests(LibTest)
\ No newline at end of file
gtest_discover_tests(LibTest)