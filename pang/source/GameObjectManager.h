//
// Created by Alessandro Lira on 2019-05-11.
//

#ifndef PANG_GAMEOBJECTMANAGER_H
#define PANG_GAMEOBJECTMANAGER_H

#include "stdafx.h"
#include "VisibleGameObject.h"

class GameObjectManager {
public:
    GameObjectManager();
    ~GameObjectManager();

    void add(std::string name, VisibleGameObject* gameObject);
    void remove(std::string name);

    int getObjectCount() const;
    VisibleGameObject* get(std::string name) const;

    void drawAll(sf::RenderWindow& renderWindow);

private:
    // heart and soul of manager
    std::map<std::string, VisibleGameObject*> _gameObjects;

    // serves as a "functor" to delete eahc VisibleGameObject pointer when called
    struct GameObjectDeallocator {
        void operator()(const std::pair<std::string, VisibleGameObject*> & p) const {
            delete p.second;
        }
    };
};


#endif //PANG_GAMEOBJECTMANAGER_H
