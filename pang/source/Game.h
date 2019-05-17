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
    static sf::RenderWindow& getWindow();
    const static int SCREEN_WIDTH = 1024;
    const static int SCREEN_HEIGHT = 768;

    static sf::Clock gameClock;

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