cmake_minimum_required(VERSION 3.17)
project(Assignment_2)

set(CMAKE_CXX_STANDARD 17)

add_executable(mazesolver
        src/main.cpp
        src/maze.h
        src/maze.cpp
        src/stack.h
        src/stack.cpp
        src/maze_solver.h
        src/maze_solver.cpp)
