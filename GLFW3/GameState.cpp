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
    renderObjects.push_back(&t);
    updateObjects.push_back(&player);
    updateObjects.push_back(&t);
}

void GameState::update(){
    for(auto u: updateObjects){
        u->update();
    }
}

void GameState::draw(){
    worldHandler->renderWorld();
    //render loop
    for(auto g: renderObjects){
        g->render();
    }
}