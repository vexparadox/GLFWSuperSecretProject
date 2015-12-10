//
//  Core.cpp
//  GLFW3
//
//  Created by William Meaton on 08/12/2015.
//  Copyright © 2015 WillMeaton.uk. All rights reserved.
//

#include "Core.hpp"

void Core::setup(){
    img.loadImage("/Users/williammeaton/Desktop/GLFW3/img.jpg", 50, 50);
}

void Core::update(){
    
}

void Core::draw(){
    img.draw(x, 0);
    Graphics::drawRect(60, 60, 50, 50);
}

void Core::keyPressed(int key){
    switch(key){
        case 263:
            x--;
            break;
        case 262:
            x++;
            break;
    }
}

void Core::keyReleased(int key){
    
}