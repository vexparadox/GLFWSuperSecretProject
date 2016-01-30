//
//  MapCreationState.cpp
//  Project2
//
//  Created by William Meaton on 28/01/2016.
//  Copyright © 2016 WillMeaton.uk. All rights reserved.
//

#include "MapCreationState.hpp"


MapCreationState::MapCreationState(){
    
}

MapCreationState::~MapCreationState(){
    
}

void MapCreationState::update(){
    if(InputHandler::getInstance()->getDOWN()){
        y+=2;
    }
    //if the mouse is press, get a grid position
    if(InputHandler::getInstance()->getMOUSE0()){
        float temp = (InputHandler::getInstance()->getMouseX()+x)/SPRITE_CODE::SPRITE_SIZE;
        float temp2 = (InputHandler::getInstance()->getMouseY()+y)/SPRITE_CODE::SPRITE_SIZE;
        std::cout << temp << " " << temp2 << std::endl;
    }

}

void MapCreationState::draw(){
    
}