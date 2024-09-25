# CMake version required
cmake_minimum_required(VERSION 3.10)

# Project name
project(FizzBuzzProject)

# Set C++ standard
set(CMAKE_CXX_STANDARD 11)

# Add the executable target (compile hw5.cpp into fizzbuzz)
add_executable(fizzbuzz hw5.cpp)
