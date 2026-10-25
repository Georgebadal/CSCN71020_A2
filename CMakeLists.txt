cmake_minimum_required(VERSION 3.10)

project(BCSRec C)

set(CMAKE_C_STANDARD 11)

enable_testing()

add_executable(BCSRec
    BCSRec/main.c
    BCSRec/functions.c
)

add_executable(unit_tests
    tests/test_functions.c
    BCSRec/functions.c
)

add_test(NAME UnitTests COMMAND unit_tests)
