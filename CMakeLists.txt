cmake_minimum_required(VERSION 3.27)
project(aramkor)

set(CMAKE_CXX_STANDARD 17)

add_executable(aramkor main.cpp
        uzenet.cpp
        uzenet.h
        aramkorielem.cpp
        aramkorielem.h
        connection.cpp
        connection.h
        vezetek.cpp
        vezetek.h
        forras.cpp
        forras.h)
