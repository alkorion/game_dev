cmake_minimum_required(VERSION 3.1...3.14)
# adjust cmake policy to maximize compatibility
if(${CMAKE_VERSION} VERSION_LESS 3.12)
    cmake_policy(VERSION ${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION})
endif()

project(pang
        VERSION 1.0
        DESCRIPTION "Starter Game: Pang"
        LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES ./source/main.cpp source/Game.cpp source/Game.h source/stdafx.cpp source/stdafx.h source/SplashScreen.h source/SplashScreen.cpp source/MainMenu.cpp source/MainMenu.h source/VisibleGameObject.cpp source/VisibleGameObject.h source/PlayerPaddle.cpp source/PlayerPaddle.h source/GameObjectManager.cpp source/GameObjectManager.h)

add_executable(pang ${SOURCE_FILES})

find_package(SFML COMPONENTS graphics window system)

target_link_libraries(pang sfml-system sfml-window sfml-graphics sfml-audio)
