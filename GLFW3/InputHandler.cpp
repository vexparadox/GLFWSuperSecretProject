//
//  InputHandler.cpp
//  Project2
//
//  Created by William Meaton on 31/12/2015.
//
//

#include "InputHandler.hpp"

InputHandler* InputHandler::instance;

InputHandler::~InputHandler(){
    delete instance;
    instance = nullptr;
}

InputHandler* InputHandler::getInstance(){
    if(!instance){
        instance = new InputHandler;
    }
    return instance;
}

void InputHandler::mouseInput(int x, int y){
    this->mouseX = x;
    this->mouseY = y;
}

int InputHandler::getMouseX(){
    return mouseX;
}

int InputHandler::getMouseY(){
    return mouseY;
}

void InputHandler::keyDown(int key){
    
    isKeyPressed = true;
    switch(key){
            //LEFT ARROW
        case 263:
            LEFT = true;
            break;
            //LETTER A
        case 65:
            LEFT = true;
            break;
            //UP ARROW
        case 265:
            UP = true;
            break;
            //LETTER W
        case 87:
            UP = true;
            break;
            //RIGHT ARROW
        case 262:
            RIGHT = true;
            break;
            //LETTER D
        case 68:
            RIGHT = true;
            break;
            //DOWN ARROR
        case 264:
            DOWN = true;
            break;
            //LETTER S
        case 83:
            DOWN = true;
            break;
            //SPACE BAR
        case 32:
            SPACE = true;
            break;
    }
}

void InputHandler::keyUp(int key){
    isKeyPressed = false;
    switch(key){
        case 263:
            LEFT = false;
            break;
        case 265:
            UP = false;
            break;
        case 262:
            RIGHT = false;
            break;
        case 264:
            DOWN = false;
            break;
        case 32:
            SPACE = false;
            break;
            //LETTER S
        case 83:
            DOWN = false;
            break;
            //LETTER D
        case 68:
            RIGHT = false;
            break;
            //LETTER W
        case 87:
            UP = false;
            break;
            //LETTER A
        case 65:
            LEFT = false;
            break;
    }
}

void InputHandler::mouseDown(int button){
    isMousePressed = true;
    switch(button){
        case 0:
            MOUSE0 = true;
            break;
        case 1:
            MOUSE1 = true;
            break;
    }
}

void InputHandler::mouseUp(int button){
    isMousePressed = false;
    switch(button){
        case 0:
            MOUSE0 = false;
            break;
        case 1:
            MOUSE1 = false;
            break;
    }
}

bool InputHandler::getMOUSE1(){
    return MOUSE1;
}

bool InputHandler::getMOUSE0(){
    return MOUSE0;
}

bool InputHandler::getisMousePressed(){
    return isMousePressed;
}

bool InputHandler::getSPACE(){
    return SPACE;
}

bool InputHandler::getUP(){
    return UP;
}


bool InputHandler::getDOWN(){
    return DOWN;
}

bool InputHandler::getLEFT(){
    return LEFT;
}

bool InputHandler::getRIGHT(){
    return RIGHT;
}
bool InputHandler::getisKeyPressed(){
    return isKeyPressed;
}