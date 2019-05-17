//
// Created by Alessandro Lira on 2019-05-17.
//
#include "stdafx.h"

#include "GameBall.h"

GameBall::GameBall() {
    load("resources/ball.png");
    assert(isLoaded());

    getSprite().setOrigin(15,15); // set origin at center of texture size
}

GameBall::~GameBall() {}