cmake_minimum_required(VERSION 3.10)
project(smart-pointers)

set(CMAKE_CXX_STANDARD 11)

# Include the shared_ptr directory
include_directories(shared_ptr)

# Add the main executable and source files
add_executable(smart_pointers main.cpp shared_ptr/shared_ptr.cpp)