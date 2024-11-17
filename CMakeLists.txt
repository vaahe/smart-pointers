cmake_minimum_required(VERSION 3.14)
project(smart-pointers)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(shared_ptr, unique_ptr)

# Add GoogleTest to the project
# add_subdirectory(googletest)
# enable_testing()

# Main executable
set(SOURCE_FILES main.cpp)
add_executable(smart_pointers ${SOURCE_FILES})
target_include_directories(smart_pointers PRIVATE shared_ptr unique_ptr)