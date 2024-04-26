cmake_minimum_required(VERSION 3.27)
project(aramkor)

set(CMAKE_CXX_STANDARD 17)
add_compile_options(-Wall -Werror -pedantic)
add_executable(aramkor main.cpp
        uzenet.cpp
        uzenet.h
        aramkorielem.cpp
        aramkorielem.h
        vezetek.cpp
        vezetek.h
        forras.cpp
        forras.h
        norgate.cpp
        norgate.h
        teszthalozat.cpp
        teszthalozat.h
        invereter.cpp
        invereter.h
        memtrace.cpp
        memtrace.h
        halozat.cpp)

