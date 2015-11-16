cmake_minimum_required(VERSION 3.3)
project(Red_Black_Tree_Project)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp red_black_template.h.h)
add_executable(Red_Black_Tree_Project ${SOURCE_FILES} red_black_template.h.h)
