cmake_minimum_required(VERSION 3.13)
project(GreenFox)

set(CMAKE_CXX_STANDARD 14)

add_executable(GreenFox main.cpp Person.cpp Person.h Student.cpp Student.h Mentor.cpp Mentor.h)