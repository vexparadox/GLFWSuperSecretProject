//
//  Core.cpp
//  GLFW3
//
//  Created by William Meaton on 08/12/2015.
//  Copyright © 2015 WillMeaton.uk. All rights reserved.
//

#include "Core.hpp"

void Core::setup(){
    img.loadImage("img.jpg", 433, 512);
    std::cout<<img.isLoaded();
}

void Core::update(){
}

void Core::draw(){
    img.draw(0, 0);
}

void Core::keyPressed(int key){
    
}

void Core::keyReleased(int key){
    
}