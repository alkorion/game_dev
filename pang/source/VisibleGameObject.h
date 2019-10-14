//
// Created by Alessandro Lira on 2019-05-06.
//

#ifndef PANG_VISIBLEGAMEOBJECT_H
#define PANG_VISIBLEGAMEOBJECT_H

#include "stdafx.h"

class VisibleGameObject {
public:
    VisibleGameObject();
    virtual ~VisibleGameObject();

    virtual void load(std::string filename);
    virtual void draw(sf::RenderWindow &renderWindow);
    virtual void update(float elapsedTime);

    virtual void setPosition(float x, float y);
    virtual sf::Vector2f getPosition() const;
//    virtual float getHeight();
//    virtual float getWidth();
//
//    virtual sf::Rect<float> getBoundingRect();

    virtual bool isLoaded() const;

protected:
    sf::Sprite& getSprite();

private:
    sf::Sprite _sprite;
    sf::Texture _texture;
    std::string _filename;
    bool _isLoaded;

};


#endif //PANG_VISIBLEGAMEOBJECT_H
