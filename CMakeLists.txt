cmake_minimum_required(VERSION 3.29)
project(arkin)

option(ARKIN_BUILD_TESTS "Build tests." OFF)
option(ARKIN_BUILD_SHARED_LIB "Build shared library." OFF)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED true)
set(CMAKE_EXPORT_COMPILE_COMMANDS true)

if (ARKIN_BUILD_SHARED_LIB)
    set(ARKIN_LIB_TYPE SHARED)
else ()
    set(ARKIN_LIB_TYPE STATIC)
endif ()

add_library(arkin ${ARKIN_LIB_TYPE}
    src/arkin_core.c
    src/arkin_log.c
    src/arkin_test.c)

target_include_directories(arkin PUBLIC "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>")

if (ARKIN_BUILD_TESTS)
    add_executable(test
        tests/main.c
        tests/core.c)
    target_link_libraries(test arkin)
    target_include_directories(test PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/tests/")
endif ()