cmake_minimum_required(VERSION 2.7)
project(TP_Game)

set(CMAKE_CXX_STANDARD 11)

add_executable(TP_Game main.cpp AllClasses.h Tower.h TowerComponents.h Player.cpp Points.cpp TowerComponents.cpp Towers.cpp)