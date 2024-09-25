# CMake version required
cmake_minimum_required(VERSION 3.20)

# Project name
project(FizzBuzzProject)

# Set C++ standard
message("Using sources: hw5.cpp") 

# Add the executable target (compile hw5.cpp into fizzbuzz)
add_executable(fizzbuzz hw5.cpp)
target_compile_features(fizzbuzz PRIVATE cxx_std_17)
install( TARGETS fizzbuzz DESTINATION bin )
install( FILES run.sh DESTINATION share) 
