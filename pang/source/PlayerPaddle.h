//
// Created by Alessandro Lira on 2019-05-07.
//

#ifndef PANG_PLAYERPADDLE_H
#define PANG_PLAYERPADDLE_H

#include "stdafx.h"

#include "PlayerPaddle.h"

#include "VisibleGameObject.h"

class PlayerPaddle: public VisibleGameObject {
public:
    PlayerPaddle();
    ~PlayerPaddle();

    void update(float elapsedTime);
    void draw(sf::RenderWindow& renderwindow);

    float getVelocity() const;

private:
    float _velocity; // -- left, ++ right
    float _maxVelocity;

};


#endif //PANG_PLAYERPADDLE_H
