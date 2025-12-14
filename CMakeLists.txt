cmake_minimum_required(VERSION 4.1)
project(advent_of_code_2025 C)

set(CMAKE_C_STANDARD 17)

add_executable(day01 day01/main.c)

add_executable(day02 day02/main.c
    day02/day02.c
)

add_executable(day03 day03/main.c
    day03/day03.c
)

add_library(unity external/unity/src/unity.c)
target_include_directories(unity PUBLIC external/unity/src)

add_executable(day02_test day02/day02_test.c
    day02/day02.c
)
target_link_libraries(day02_test unity)

add_executable(day03_test day03/day03_test.c
    day03/day03.c
)
target_link_libraries(day03_test unity)
