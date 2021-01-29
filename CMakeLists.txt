cmake_minimum_required(VERSION 3.17)
project(KMeansClustering_OpenMP)

set(CMAKE_CXX_STANDARD 20)

# added -fopenmp
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}  -fopenmp")

add_executable(KMeansClustering_OpenMP main.cpp Point.cpp Point.h KMeans.cpp KMeans.h)