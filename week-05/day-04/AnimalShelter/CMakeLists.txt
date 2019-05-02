cmake_minimum_required(VERSION 3.13)
project(AnimalShelter)

set(CMAKE_CXX_STANDARD 14)

add_executable(AnimalShelter main.cpp Animal.cpp Animal.h Cat.cpp Cat.h Dog.cpp Dog.h Parrot.cpp Parrot.h Shelter.cpp Shelter.h)