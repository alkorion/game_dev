//
// Created by Alessandro Lira on 2019-05-06.
//

#include "stdafx.h"

#include "VisibleGameObject.h"

VisibleGameObject::VisibleGameObject() {
    _isLoaded = false;
}

VisibleGameObject::~VisibleGameObject() {
}

void VisibleGameObject::load(std::string filename) {
    if(_texture.loadFromFile(filename) == false) {
        _filename = "";
        _isLoaded = false;
    }
    else {
        _filename = filename;
        _sprite.setTexture(_texture);
        _isLoaded = true;
    }
}

void VisibleGameObject::draw(sf::RenderWindow &renderWindow) {
    if(_isLoaded) {
        renderWindow.draw(_sprite);
    }
}

void VisibleGameObject::update(float elapsedTime) {
}

void VisibleGameObject::setPosition(float x, float y) {
    if(_isLoaded) {
        _sprite.setPosition(x,y);
    }
}

sf::Vector2f VisibleGameObject::getPosition() const {
    if(_isLoaded) {
        return _sprite.getPosition();
    }
    return sf::Vector2f();
}

//float VisibleGameObject::getHeight() {
//    return _sprite.getTexture()->getSize().y;
//}
//
//float VisibleGameObject::getWidth() {
//    return _sprite.getTexture()->getSize().x;
//}
//
//sf::Rect<float> VisibleGameObject::getBoundingRect() {
//    //sf::Vector2f size = _sprite.getTexture()->getSize().x;
//    sf::Vector2f size = sf::Vector2f((float)_sprite.getTexture()->getSize().x,(float)_sprite.getTexture()->getSize().y);
//    sf::Vector2f pos = _sprite.getPosition();
//
//    return sf::Rect<float>(
//            pos.x - size.x/2,
//            pos.y - size.y/2,
//            pos.x + size.x/2,
//            pos.y + size.y/2
//            );
//}

sf::Sprite& VisibleGameObject::getSprite() {
    return _sprite;
}

bool VisibleGameObject::isLoaded() const {
    return _isLoaded;
}