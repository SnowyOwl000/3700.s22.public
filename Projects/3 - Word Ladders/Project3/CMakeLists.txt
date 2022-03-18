cmake_minimum_required(VERSION 3.14)
project(Project3)

set(CMAKE_CXX_STANDARD 17)

include_directories($ENV{HOME}/Programming/include)

add_executable(Project3 main.cpp)