
cmake_minimum_required(VERSION 3.15)
project(Objektinis VERSION 1.0 DESCRIPTION "Student grade management system" LANGUAGES CXX)

# Prefer Release when not specified
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release CACHE STRING "Build type" FORCE)
endif()

# C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Compiler flags: prefer portable flags; Release is optimized by default
if(NOT CMAKE_CXX_FLAGS)
    set(CMAKE_CXX_FLAGS "-O2")
endif()

# Main executable (source files only)
add_executable(main
    main.cpp
    funkcijos.cpp
)

# Set runtime output directory
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Installation rules: install binary and documentation
install(TARGETS main RUNTIME DESTINATION bin)

install(FILES README.md INSTALLATION.md DESTINATION share/doc/Objektinis)

# Print build info
message(STATUS "Building Objektinis v${PROJECT_VERSION}")
message(STATUS "C++ Standard: ${CMAKE_CXX_STANDARD}")
message(STATUS "Build type: ${CMAKE_BUILD_TYPE}")
