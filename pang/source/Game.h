//
// Created by Alessandro Lira on 2019-04-19.
//

#ifndef PANG_GAME_H
#define PANG_GAME_H

#include "stdafx.h"
#include "GameObjectManager.h"

class Game {

public:
    static void start();

private:
    static bool isExiting();
    static void gameLoop();

    static void showSplashScreen();
    static void showMainMenu();

    enum GameState { Uninitialized, ShowingSplashScreen, Paused, ShowingMenu, Playing, Exiting};

    static GameState _gameState;
    static sf::RenderWindow _mainWindow;

    static GameObjectManager _gameObjectManager;
};

#endif //PANG_GAME_H