//
// Created by Alessandro Lira on 2019-05-11.
//

#include "stdafx.h"
#include "GameObjectManager.h"

GameObjectManager::GameObjectManager() {}

GameObjectManager::~GameObjectManager() {
    // loop through each gameObject and feed it to the GameObjectDeallocator() functor
    std::for_each(_gameObjects.begin(),_gameObjects.end(),GameObjectDeallocator());
    // NOTE: GameObjectDeallocator simply deletes the pointer located at std::pair.second
}

// add a VisibleGameObject to the _gameObjects std::map
void GameObjectManager::add(std::string name, VisibleGameObject *gameObject) {
    // add new game object as a std::pair value set (string "name" and VisibleGameObject-pointer "gameObject")
    _gameObjects.insert(std::pair<std::string, VisibleGameObject*>(name,gameObject));
}

// delete the corresponding pointer for a game object
void GameObjectManager::remove(std::string name) {
    std::map<std::string, VisibleGameObject*>::iterator results = _gameObjects.find(name);
    if(results != _gameObjects.end()) {
        delete results->second; // delete pointer located at (*results).second (i.e. the VisibleGameObject* pointer)
        _gameObjects.erase(results);
    }
}

// return the desired game object (if it exists) by referencing its name
VisibleGameObject* GameObjectManager::get(std::string name) const {
    std::map<std::string, VisibleGameObject*>::const_iterator results = _gameObjects.find(name);
    if(results == _gameObjects.end()) { // check if result of find() operation is null result
        return NULL;
    }
    return results->second; // return the member "second" of the objects results is pointing at
    // equivalent to return (*results).second;
}

// wrapper function of std::map size() function
int GameObjectManager::getObjectCount() const {
    return _gameObjects.size();
}

// loop through all game objects and use their draw methods on the provided renderWindow
void GameObjectManager::drawAll(sf::RenderWindow &renderWindow) {
    std::map<std::string, VisibleGameObject*>::const_iterator itr = _gameObjects.begin(); // TODO: see if this needs const_iterator?
    // while the game-object iterator is NOT pointing at the final NULL value, draw each object
    while(itr != _gameObjects.end()) {
        itr->second->draw(renderWindow);
        itr++;
    }
}
