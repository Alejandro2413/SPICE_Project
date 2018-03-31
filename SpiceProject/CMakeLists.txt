cmake_minimum_required(VERSION 2.6)
set (CMAKE_CXX_STANDARD 11)
project(SPICE)

include_directories(include)
add_library(Circuit src/Circuit.cpp)
add_library(Component src/Component.cpp)
add_library(Resistor src/Resistor.cpp)
add_library(CurrentSource src/CurrentSource.cpp)