//
//  GameState.cpp
//  Project2
//
//  Created by William Meaton on 21/01/2016.
//  Copyright © 2016 WillMeaton.uk. All rights reserved.
//

#include "GameState.hpp"

GameState::GameState(){
    SpriteHandler::getInstance()->loadImages();
    WorldHandler::getInstance()->loadWorld(0);
}

void GameState::update(){
    
}

void GameState::draw(){
    WorldHandler::getInstance()->renderWorld();
}