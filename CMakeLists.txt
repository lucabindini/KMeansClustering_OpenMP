cmake_minimum_required(VERSION 3.17)
project(KMeansClustering_OpenMP)

set(CMAKE_CXX_STANDARD 20)

add_executable(KMeansClustering_OpenMP main.cpp Point.cpp Point.h)