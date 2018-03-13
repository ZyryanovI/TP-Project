cmake_minimum_required(VERSION 2.8)
include_directories(.)
include_directories(Towers)
add_executable(main Source.cpp Player.cpp Points.cpp Towers/Towers.cpp Towers/TowerComponents.cpp AllClasses.h Towers/Tower.h Towers/TowerComponents.h)