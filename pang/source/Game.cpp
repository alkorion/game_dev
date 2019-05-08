//
// Created by Alessandro Lira on 2019-04-19.
//

#include "stdafx.h"
#include "Game.h"

void Game::start(void)
{
    if(_gameState != Uninitialized) {
        return;
    }

    _mainWindow.create(sf::VideoMode(1024,768,32),"Pang!");
    _gameState = Game::ShowingSplashScreen;

    while(!isExiting()) {
        gameLoop();
    }

    _mainWindow.close();
}

bool Game::isExiting()
{
    if(_gameState == Game::Exiting)
        return true;
    else
        return false;
}

void Game::gameLoop()
{
    sf::Event currentEvent;
    while(_mainWindow.pollEvent(currentEvent))
    {

        switch(_gameState)
        {
            case Game::ShowingMenu:
            {
                showMainMenu();
                break;
            }
            case Game::ShowingSplashScreen:
            {
                showSplashScreen();
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

void Game::showSplashScreen() {
    SplashScreen splashScreen;
    splashScreen.show(_mainWindow);
    _gameState = Game::ShowingMenu;
}

void Game::showMainMenu() {
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


