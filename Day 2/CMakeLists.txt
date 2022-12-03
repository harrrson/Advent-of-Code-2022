cmake_minimum_required(VERSION 3.22)
project(AoC-Day2)

set(INPUT_PATH "${CMAKE_SOURCE_DIR}/input.txt")
set(AOC_DAY 2)

configure_file (myconfig.h.in myconfig.h @ONLY)

add_executable(${CMAKE_PROJECT_NAME} main.cpp)

include_directories (${CMAKE_CURRENT_BINARY_DIR})