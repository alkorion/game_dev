//
// Created by Alessandro Lira on 2019-05-07.
//

#include "stdafx.h"

#include "PlayerPaddle.h"

#include "Game.h"

PlayerPaddle::PlayerPaddle():
_velocity(0),
_maxVelocity(600.0f)
{
    load("resources/paddle.png");
    assert(isLoaded());

    getSprite().setOrigin(getSprite().getTexture()->getSize().x/2, getSprite().getTexture()->getSize().y/2);
}

PlayerPaddle::~PlayerPaddle() {}

void PlayerPaddle::draw(sf::RenderWindow& rw) {
    VisibleGameObject::draw(rw);
}

float PlayerPaddle::getVelocity() const {
    return _velocity;
}

void PlayerPaddle::update(float elapsedTime) {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left)) {
        _velocity -= 3.0f;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right)) {
        _velocity += 3.0f;
    }
    // stop paddle if Down key pressed
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down)) {
        _velocity = 0.0f;
    }
    // bound velocity values after calculation
    if(_velocity > _maxVelocity) {
        _velocity = _maxVelocity;
    }
    if(_velocity < -_maxVelocity) {
        _velocity = -_maxVelocity;
    }

    sf::Vector2f pos = this->getPosition();

    if( (pos.x < getSprite().getTextureRect().width/2 && _velocity < 0) ||
    (pos.x > Game::SCREEN_WIDTH - getSprite().getTextureRect().width/2 && _velocity > 0)) {
        _velocity = -_velocity; // bounce paddle elastically off wall in other direction
    }

    getSprite().move(_velocity * elapsedTime, 0);
}