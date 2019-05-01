cmake_minimum_required(VERSION 3.13)
project(pang)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES ./source/main.cpp source/Game.cpp source/Game.h source/stdafx.cpp source/stdafx.h source/SplashScreen.h source/SplashScreen.cpp source/MainMenu.cpp source/MainMenu.h)

add_executable(pang ${SOURCE_FILES})

find_package(SFML COMPONENTS graphics window system)

target_link_libraries(pang sfml-system sfml-window sfml-graphics sfml-audio)
