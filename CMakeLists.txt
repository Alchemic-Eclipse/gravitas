cmake_minimum_required(VERSION 3.20)

project(gravitas)

set(CMAKE_CXX_STANDARD 20)

find_package(raylib REQUIRED)

add_executable(gravitas main.cpp
        physics.cpp
        physics.h
        renderer.cpp
        renderer.h)

target_link_libraries(gravitas PRIVATE raylib)