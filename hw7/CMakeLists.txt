# CMake version required
cmake_minimum_required(VERSION 3.20)

# Project name
project(Homework7)

# Add the executable target (compile hw7.cpp into Homework7)
add_executable(Homework7 hw7.cpp)

# Set C++ standard to C++17
target_compile_features(Homework7 PRIVATE cxx_std_17)

# Install the executable to the bin directory
install(TARGETS Homework7 DESTINATION bin)

# Install the run.sh script to the share directory
install(FILES run.sh DESTINATION share)
 
