cmake_minimum_required(VERSION 3.22)
project(AoC-Day1)

set(INPUT_PATH "${CMAKE_SOURCE_DIR}/part1-input.txt")
set(AOC_DAY 1)

configure_file (myconfig.h.in myconfig.h @ONLY)

add_executable(${CMAKE_PROJECT_NAME} main.cpp)

include_directories (${CMAKE_CURRENT_BINARY_DIR})