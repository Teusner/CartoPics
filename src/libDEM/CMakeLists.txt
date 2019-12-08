cmake_minimum_required(VERSION 3.3)

project(libDEM VERSION 1.0)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(CMAKE_BUILD_TYPE Debug)

add_subdirectory(delaunator)

set(SRCS DEM.cpp)
set(HEADERS DEM.h)

add_library(DEM ${SRCS} ${HEADERS})

target_link_libraries(DEM delaunator)