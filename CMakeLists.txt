cmake_minimum_required(VERSION 3.23)
project(Matrix)

set(CMAKE_CXX_STANDARD 14)

add_library(matrix src/bitvector.cpp src/bmatrix.cpp)
add_executable(Matrix main.cpp src/bitvector.cpp src/bmatrix.cpp)
target_link_libraries(matrix)
add_subdirectory(Google_tests)
