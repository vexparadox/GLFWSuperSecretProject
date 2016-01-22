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

Core::~Core(){
    delete gameState;
    gameState = nullptr;
}

void Core::setup(){
    //this needs to be set here otherwise c
    gameState = new GameState();
    State::setState(gameState);
}

void Core::update(){
    State::getCurrentState()->update();
}

void Core::draw(){
    State::getCurrentState()->draw();
}

void Core::keyPressed(int key){
    
}

void Core::keyReleased(int key){
    
}

void Core::mousePressed(int button){
    std::cout << button;
}

void Core::mouseReleased(int button){
    
}