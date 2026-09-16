cmake_minimum_required(VERSION 3.20)

set(CMAKE_OSX_DEPLOYMENT_TARGET "26.0" CACHE STRING "Minimum macOS version")

project(gravitas)

set(CMAKE_CXX_STANDARD 20)

find_package(raylib REQUIRED)

add_executable(gravitas MACOSX_BUNDLE
        src/main.cpp
        src/physics.cpp
        include/physics.h
        src/renderer.cpp
        include/renderer.h)

target_link_libraries(gravitas PRIVATE raylib)