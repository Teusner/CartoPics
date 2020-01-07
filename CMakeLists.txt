cmake_minimum_required(VERSION 2.8.3)

project(create_raster)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(CMAKE_BUILD_TYPE Debug)



find_package(Eigen3)
find_package(Boost 1.55 REQUIRED COMPONENTS unit_test_framework)

include_directories(include)

add_library(DEM src/DEM.cpp)
add_library(Pixel src/Pixel.cpp)
add_library(Triangle src/Triangle.cpp)
add_library(Point src/Point.cpp)
add_library(tools src/tools.cpp)

add_executable(create_raster src/main.cpp)
target_link_libraries(create_raster DEM Pixel Triangle Point tools)


# ctest
include_directories(${Boost_INCLUDE_DIR})

enable_testing()

add_executable(test_Pixel_exe test/test_Pixel)
target_link_libraries(test_Pixel_exe ${Boost_LIBRARIES} Pixel)
add_test(PixelTest test_Pixel_exe)

add_executable(test_Point_exe test/test_Point)
target_link_libraries(test_Point_exe ${Boost_LIBRARIES} Point)
add_test(PointTest test_Point_exe)

add_executable(test_Triangle_exe test/test_Triangle)
target_link_libraries(test_Triangle_exe ${Boost_LIBRARIES} Triangle Point)
add_test(TriangleTest test_Triangle_exe)