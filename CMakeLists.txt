cmake_minimum_required(VERSION 3.9)
project(KMA_OOP_04Lab)

set(CMAKE_CXX_STANDARD 98)

add_executable(KMA_OOP_04Lab
        src/Point/Point.h
        src/Point/Point.cpp
        src/Segment/Segment.h
        src/Segment/Segment.cpp
        src/unittest_main.cpp src/Triangle.h)