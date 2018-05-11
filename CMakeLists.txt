cmake_minimum_required(VERSION 3.1)

project(trees)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED on)

include_directories("headers/")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")
#set(SOURCES no_headers/main.cpp no_headers/Container.cpp no_headers/SimpleTree.cpp) или ели хотим меньше кода:
file(GLOB SOURCES "no_headers/*.cpp")
add_executable(trees ${SOURCES})
