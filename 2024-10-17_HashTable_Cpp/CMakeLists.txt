cmake_minimum_required(VERSION 3.29)
project(CppHashtable)

set(CMAKE_CXX_STANDARD 20)

add_executable(CppHashtable main.cpp
        MyHashtable.cpp
        MyHashtable.h)
