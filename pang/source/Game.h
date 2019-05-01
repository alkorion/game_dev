//
// Created by Alessandro Lira on 2019-04-19.
//

#ifndef KANJI_KOMBAT_GAME_H
#define KANJI_KOMBAT_GAME_H

#include "stdafx.h"

class Game {

public:
    static void Start();

private:
    static bool IsExiting();
    static void GameLoop();

    static void ShowSplashScreen();
    static void ShowMainMenu();

    enum GameState { Uninitialized, ShowingSplashScreen, Paused, ShowingMenu, Playing, Exiting};

    static GameState _gameState;
    static sf::RenderWindow _mainWindow;
};

#endif //KANJI_KOMBAT_GAME_H