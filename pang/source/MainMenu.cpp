//
// Created by Alessandro Lira on 2019-04-20.
//

#include "stdafx.h"
#include "MainMenu.h"

MainMenu::MenuResult MainMenu::show(sf::RenderWindow &window) {
    // load menu background from image file
    sf::Texture menu_texture;
    menu_texture.loadFromFile("resources/main_menu.png");
    sf::Sprite menu_sprite(menu_texture);


    // Setup clickable regions

    // Play menu-item coords
    MenuItem playButton;
    playButton.rect.top = 145;
    playButton.rect.height = 235;
    playButton.rect.left = 0;
    playButton.rect.width = 1024;
    playButton.action = Play;

    // Exit menu-item coords
    MenuItem exitButton;
    exitButton.rect.top = 380;
    exitButton.rect.height = 180;
    exitButton.rect.left = 0;
    exitButton.rect.width = 1024;
    exitButton.action = Exit;

    _menuItems.push_back(playButton);
    _menuItems.push_back(exitButton);

    window.draw(menu_sprite);
    window.display();

    return getMenuResponse(window);
}

MainMenu::MenuResult MainMenu::handleClick(int x, int y) {

    // create iterator 'it' which is a pointer for items in a list
    std::vector<MenuItem>::iterator it;

    for (it = _menuItems.begin(); it != _menuItems.end(); it++) {

        sf::Rect<int> menuItemRect = (*it).rect;

        if( y > menuItemRect.top &&
            y < (menuItemRect.top + menuItemRect.height) &&
            x > menuItemRect.left &&
            x < (menuItemRect.left + menuItemRect.width)) {
            // if mouse coords are inside of menu-item coords
            return (*it).action;
        }
    }

    return Nothing;
}

MainMenu::MenuResult MainMenu::getMenuResponse(sf::RenderWindow& window) {
    sf::Event menuEvent;

    while(true) {
        while(window.pollEvent(menuEvent)) {
            if(menuEvent.type == sf::Event::MouseButtonPressed) {
                return handleClick(menuEvent.mouseButton.x,menuEvent.mouseButton.y);
            }
            if(menuEvent.type == sf::Event::Closed) {
                return Exit;
            }
        }
    }
}
