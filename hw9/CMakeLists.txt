#Name: Orlan Oconer
#EID: ojo366
#TACC username: orlan


# CMake version required
cmake_minimum_required(VERSION 3.20)

# Project name
project(Homework9)

# Add the executable target (compile hw7.cpp into Homework7)
add_executable(Homework9 hw9.cpp)

# Set C++ standard to C++17
target_compile_features(Homework9 PRIVATE cxx_std_17)

# Install the executable to the bin directory
install(TARGETS Homework9 DESTINATION bin)

# Install the run.sh script to the share directory
install(FILES run.sh DESTINATION share)
 
