cmake_minimum_required(VERSION 3.14)
project(cpp-tools)

# GoogleTest requires at least C++14
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory("${CMAKE_SOURCE_DIR}/thirdparty/googletest-1.14.0")
add_subdirectory(cpp_tools)