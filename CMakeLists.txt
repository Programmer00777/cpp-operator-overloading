cmake_minimum_required(VERSION 3.23)
project(lb2)

set(CMAKE_CXX_STANDARD 14)

add_executable(lb2 main.cpp Set.h RandomSetGenerator.h SetService.h)
