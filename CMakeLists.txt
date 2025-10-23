cmake_minimum_required(VERSION 4.0)
project(First_assignment)

set(CMAKE_CXX_STANDARD 20)

add_executable(First_assignment main.cpp
        calculations.cpp
        calculations.h
        functions.cpp
        functions.h
        statistics.cpp
        statistics.h
)
