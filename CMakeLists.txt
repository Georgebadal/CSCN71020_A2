cmake_minimum_required(VERSION 3.14)

project(BCSRec LANGUAGES C CXX)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

include(FetchContent)

FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)

FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(BCSRec
    BCSRec/main.c
    BCSRec/functions.c
)

add_executable(unit_tests
    tests/test_functions.cpp
    BCSRec/functions.c
)

target_link_libraries(unit_tests GTest::gtest)


include(GoogleTest)
gtest_discover_tests(unit_tests)