cmake_minimum_required(VERSION 3.14)
project(PC2)

set(CMAKE_CXX_STANDARD 14)

add_executable(PC2 main.cpp Defense.h Attack.h Fighter.cpp Fighter.h Arena.cpp Arena.h Tester.h)