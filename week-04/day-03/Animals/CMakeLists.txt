cmake_minimum_required(VERSION 3.13)
project(Animals)

set(CMAKE_CXX_STANDARD 14)

add_executable(Animals main.cpp Animal.h Reptile.cpp Reptile.h Mammal.cpp Mammal.h Bird.cpp Bird.h)