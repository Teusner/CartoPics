cmake_minimum_required(VERSION 3.3)

project(DEM VERSION 1.0)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(CMAKE_BUILD_TYPE Debug)

add_subdirectory(libDEM)

set(SRCS main.cpp)

add_executable(cartopics ${SRCS} ${HEADERS})

target_link_libraries(cartopics DEM delaunator)