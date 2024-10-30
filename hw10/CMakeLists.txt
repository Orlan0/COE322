cmake_minimum_required(VERSION 3.20)
project(zeroclasstest VERSION 1.0)

# Set C++ Standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Enable extra warnings
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")

# Set output directory for executables
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Print debug information
message(STATUS "Source directory: ${CMAKE_CURRENT_SOURCE_DIR}")
message(STATUS "Build directory: ${CMAKE_BINARY_DIR}")

# Add the executable with source files
add_executable(zeroclasstest
    ${CMAKE_CURRENT_SOURCE_DIR}/zeroclasstest.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/hw10.cpp
)

##
## Extra packages: Catch2
##
find_package(PkgConfig REQUIRED)
pkg_check_modules(CATCH2 REQUIRED catch2-with-main)

# Check if Catch2 is found
if(NOT CATCH2_FOUND)
    message(FATAL_ERROR "Catch2 not found!")
endif()

# Print Catch2 debug information
message(STATUS "Catch2 include dirs: ${CATCH2_INCLUDE_DIRS}")
message(STATUS "Catch2 library dirs: ${CATCH2_LIBRARY_DIRS}")
message(STATUS "Catch2 libraries: ${CATCH2_LIBRARIES}")

# Include directories for Catch2 and project headers
target_include_directories(zeroclasstest
    PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}  # Include directory for project headers (zeroclasslib.hpp)
    ${CATCH2_INCLUDE_DIRS}       # Include Catch2 headers
)

# Link Catch2 libraries to zeroclasstest
target_link_directories(zeroclasstest
    PRIVATE
    ${CATCH2_LIBRARY_DIRS}
)

target_link_libraries(zeroclasstest
    PRIVATE
    ${CATCH2_LIBRARIES}
)

# Set runtime paths for the executable
set_target_properties(zeroclasstest
    PROPERTIES
    BUILD_RPATH "${CATCH2_LIBRARY_DIRS}"
    INSTALL_RPATH "${CATCH2_LIBRARY_DIRS}"
)

# Install rules: place the executable in the bin directory
install(TARGETS zeroclasstest
    RUNTIME DESTINATION bin
)
