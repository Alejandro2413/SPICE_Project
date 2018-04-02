cmake_minimum_required(VERSION 2.6)
set (CMAKE_CXX_STANDARD 11)
project(SpiceProject)

include_directories(include)
add_library(circuitLibs src/circuitLibs.cpp)

add_library(Component src/Component.cpp)
target_link_libraries (Component circuitLibs)

add_library(Resistor src/Resistor.cpp)
target_link_libraries(Resistor circuitLibs Component)


add_library(CurrentSource src/CurrentSource.cpp)
target_link_libraries(CurrentSource circuitLibs Component)

add_library(Circuit src/Circuit.cpp)
target_link_libraries(Circuit circuitLibs Resistor CurrentSource)

add_executable(spiceTest src/testMain.cpp)
target_link_libraries(spiceTest circuitLibs Component CurrentSource Resistor Circuit)