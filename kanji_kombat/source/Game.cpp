//
// Created by Alessandro Lira on 2019-04-19.
//

#include "stdafx.h"
#include "Game.h"

void Game::Start(void)
{
    if(_gameState != Uninitialized) {
        return;
    }

    _mainWindow.create(sf::VideoMode(1024,768,32),"Kanji Kombat");
    _gameState = Game::ShowingSplashScreen;

    while(!IsExiting()) {
        GameLoop();
    }

    _mainWindow.close();
}

bool Game::IsExiting()
{
    if(_gameState == Game::Exiting)
        return true;
    else
        return false;
}

void Game::GameLoop()
{
    sf::Event currentEvent;
    while(_mainWindow.pollEvent(currentEvent))
    {

        switch(_gameState)
        {
            case Game::ShowingMenu:
            {
                ShowMainMenu();
                break;
            }
            case Game::ShowingSplashScreen:
            {
                ShowSplashScreen();
                break;
            }
            case Game::Playing:
            {
                _mainWindow.clear(sf::Color(0,0,0));
                _mainWindow.display();

                if(currentEvent.type == sf::Event::Closed)
                {
                    _gameState = Game::Exiting;
                }
                break;
            }
        }
    }
}

void Game::ShowSplashScreen() {
    SplashScreen splashScreen;
    splashScreen.show(_mainWindow);
    _gameState = Game::ShowingMenu;
}

void Game::ShowMainMenu() {
    MainMenu mainMenu;
    MainMenu::MenuResult result = mainMenu.show(_mainWindow);
    switch(result)
    {
        case MainMenu::Exit:
            _gameState = Exiting;
            break;
        case MainMenu::Play:
            _gameState = Playing;
            break;
    }
}

// A quirk of C++, static member variables need to be instantiated outside of the class
Game::GameState Game::_gameState = Uninitialized;
sf::RenderWindow Game::_mainWindow;


