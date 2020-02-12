cmake_minimum_required(VERSION 3.15)
project(lgnl C)

set(CMAKE_C_STANDARD 11)

include_directories(./include)

add_library(lgnl include/get_next_line.h get_next_line.c)