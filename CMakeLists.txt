cmake_minimum_required(VERSION 3.26)
project(Remake)

set(CMAKE_CXX_STANDARD 17)

add_executable(Remake src/main.cpp
        src/Changes.h
        src/Changes.cpp
        src/Ocupation.h
        src/Ocupation.cpp
        src/Schedules_Checker.cpp
        src/ListStudents.cpp
        src/Undo.cpp)
