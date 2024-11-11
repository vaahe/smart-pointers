cmake_minimum_required(VERSION 3.10)
project(smart-pointers)

set(CMAKE_CXX_STANDARD 11)

add_subdirectory(googletest)

include_directories(${CMAKE_SOURCE_DIR}/shared_ptr)
set(SOURCE_FILES main.cpp)

add_executable(smart_pointers ${SOURCE_FILES})

enable_testing()

set(TEST_FILES
    test/test_shared_ptr.cpp
)

add_executable(tests ${TEST_FILES} ${SOURCE_FILES})
target_link_libraries(tests gtest gtest_main)

add_test(NAME tests COMMAND tests)