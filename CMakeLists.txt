cmake_minimum_required(VERSION 4.0)
project(cpp_lab3_task9)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(cpp_lab3_task9 main.cpp
        synchronization.h
        workers.cpp
        workers.h)
