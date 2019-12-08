cmake_minimum_required(VERSION 3.3)

project(delaunator VERSION 1.0)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(CMAKE_BUILD_TYPE Debug)

set(SRCS delaunator.cpp)
set(HEADERS delaunator.hpp)

add_library(delaunator ${SRCS} ${HEADERS})