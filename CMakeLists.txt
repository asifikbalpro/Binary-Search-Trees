cmake_minimum_required(VERSION 3.0)
project(Binary_Search_Tree)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        main.cpp
        src/BST.cpp
        src/BST.h
        )

add_executable(Binary_Search_Tree ${SOURCE_FILES})
