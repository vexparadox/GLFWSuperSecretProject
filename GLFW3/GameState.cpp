//
//  GameState.cpp
//  Project2
//
//  Created by William Meaton on 21/01/2016.
//  Copyright © 2016 WillMeaton.uk. All rights reserved.
//

#include "GameState.hpp"

GameState::~GameState(){
    inputHandler = nullptr;
    worldHandler = nullptr;
}

GameState::GameState(){
    //load world and sprites
    SpriteHandler::getInstance()->loadImages();
    worldHandler = WorldHandler::getInstance();
    worldHandler->loadWorld(0);
    inputHandler = InputHandler::getInstance();
    //add the player to the object loop
    objects.push_back(&a);
}

void GameState::update(){
    if(a.getPosition().y > inputHandler->windowHeight){
        worldHandler->offSetYby(inputHandler->windowHeight);
        
    }
}

void GameState::draw(){
    WorldHandler::getInstance()->renderWorld();
    //render loop
    for(GameObject* g: objects){
        g->render();
    }
}