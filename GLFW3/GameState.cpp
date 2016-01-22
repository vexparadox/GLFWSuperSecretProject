//
//  GameState.cpp
//  Project2
//
//  Created by William Meaton on 21/01/2016.
//  Copyright © 2016 WillMeaton.uk. All rights reserved.
//

#include "GameState.hpp"

GameState::GameState(){
    //load world and sprites
    SpriteHandler::getInstance()->loadImages();
    WorldHandler::getInstance()->loadWorld(0);
    //add the player to the object loop
    objects.push_back(p);
}

void GameState::update(){
    std::cout << InputHandler::getInstance()->getMouseX();
}

void GameState::draw(){
    WorldHandler::getInstance()->renderWorld();
    //render loop
    for(GameObject* g: objects){
        g->render();
    }
}