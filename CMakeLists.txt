cmake_minimum_required(VERSION 3.0)

set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")

project(ship)

add_executable(
    ship
    Battaglia_Navale.cpp
    Mare.cpp
    Ship.cpp
    Nds.cpp
    Sde.cpp
    Corazzata.cpp
    Players.cpp
)