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
    worldHandler->loadWorld(2);
    inputHandler = InputHandler::getInstance();
    
    //add the player to the render and update loop
    renderObjects.push_back(&player);
    updateObjects.push_back(&player);
}

void GameState::update(){
    for(GameObject* u: updateObjects){
        u->update();
    }
}

void GameState::draw(){
    WorldHandler::getInstance()->renderWorld();
    //render loop
    for(GameObject* g: renderObjects){
        g->render();
    }
}