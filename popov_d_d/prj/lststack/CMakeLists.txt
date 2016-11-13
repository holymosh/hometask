cmake_minimum_required(VERSION 3.6)
project(lststack)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    lststack/lststack.cpp
    lststack/lststack.h
    lststack/lststacktest.cpp)

add_executable(lststack ${SOURCE_FILES})