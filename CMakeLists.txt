cmake_minimum_required(VERSION 2.8)
project(game)
set(SOURCES_LIST
	Game.cpp
	Player.cpp
	Point.cpp
	Producer.cpp
	Tower.cpp
	TowerComponents.cpp
    Composite.cpp

	AllClasses.h
	Game.h
	Player.h
	Point.h
	Producer.h
	Tower.h
	TowerComponents.h
    Composite.h)

if(DEBUG)
	set(CMAKE_BUILD_TYPE Debug)
endif()

set(CMAKE_CXX_FLAGS -std=c++11)
include_directories(.)

if(WITH_TEST)
	enable_testing()
	find_package(GTest REQUIRED)
	include_directories(.)

	add_executable(game ${SOURCES_LIST} Test.cpp)
	target_include_directories(game PUBLIC "./include")
	target_link_libraries(game PUBLIC GTest::GTest GTest::Main)

	add_test(CommonTestsAll game)
else()
	add_executable(game ${SOURCES_LIST} Main.cpp)
endif()
