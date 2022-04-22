cmake_minimum_required(VERSION 3.21.1)

project(bst-dictionary)

set(CMAKE_CXX_STANDARD 17)

add_executable(bst-dictionary main.cpp bst-dictionary.h sampler.cpp sampler.h)