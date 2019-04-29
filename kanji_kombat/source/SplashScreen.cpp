//
// Created by Alessandro Lira on 2019-04-20.
//

#include "stdafx.h"
#include "SplashScreen.h"

void SplashScreen::show(sf::RenderWindow & renderWindow) {
    sf::Texture k_spash_texture;
    // try to load texture from memory
    if (k_spash_texture.loadFromFile("resources/kanji_splash.jpg") != true) {
        return;
    }

    sf::Sprite sprite(k_spash_texture);

    renderWindow.draw(sprite);
    renderWindow.display();

    sf::Event event;
    while(true) {
        while(renderWindow.pollEvent(event)) {
            if (event.type == sf::Event::EventType::KeyPressed
            || event.type == sf::Event::EventType::MouseButtonPressed
            || event.type == sf::Event::EventType::Closed) {
                return;
            }
        }
    }
}