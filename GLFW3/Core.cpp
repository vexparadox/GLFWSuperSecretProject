//
//  Core.cpp
//  GLFW3
//
//  Created by William Meaton on 08/12/2015.
//  Copyright © 2015 WillMeaton.uk. All rights reserved.
//

#include "Core.hpp"
//for graphics
using namespace Graphics;
void Core::setup(){
    SpriteHandler::getInstance()->loadImages();
    WorldHandler::getInstance()->loadWorld(0);
}

void Core::update(){
    
}

void Core::draw(){
    WorldHandler::getInstance()->renderWorld();
}

void Core::keyPressed(int key){
    
}

void Core::keyReleased(int key){
    
}