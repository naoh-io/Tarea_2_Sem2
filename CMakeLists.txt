cmake_minimum_required(VERSION 3.20)
project(CoreNumeric)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(Tarea-2-Sem-2 main.cpp
        core_numeric.h
        test.cpp)