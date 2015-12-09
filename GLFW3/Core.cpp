//
//  Core.cpp
//  GLFW3
//
//  Created by William Meaton on 08/12/2015.
//  Copyright © 2015 WillMeaton.uk. All rights reserved.
//

#include "Core.hpp"

void Core::setup(){
    std::cout << Runner::windowHeight;
}

void Core::update(){
    
}

void Core::draw(){
    Graphics::drawRect(x++, 30, 50, 50);
}
