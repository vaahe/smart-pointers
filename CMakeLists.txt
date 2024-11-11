cmake_minimum_required(VERSION 3.10)
project(smart-pointers)

set(CMAKE_CXX_STANDARD 11)

include_directories(shared_ptr)
set(SOURCE_FILES main.cpp)

add_executable(smart_pointers ${SOURCE_FILES})