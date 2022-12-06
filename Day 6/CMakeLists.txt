cmake_minimum_required(VERSION 3.22)
project(AoC-Day6)

set(CMAKE_CXX_STANDARD 20)

set(INPUT_PATH "${CMAKE_SOURCE_DIR}/input.txt")
set(AOC_DAY 6)

configure_file (myconfig.h.in myconfig.h @ONLY)

add_executable(${CMAKE_PROJECT_NAME} main.cpp)

include_directories (${CMAKE_CURRENT_BINARY_DIR})