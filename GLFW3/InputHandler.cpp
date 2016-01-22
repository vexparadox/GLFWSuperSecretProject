//
//  Keyboard.cpp
//  LabOF1
//
//  Created by William Meaton on 09/11/2015.
//
//

#include "InputHandler.hpp"

bool InputHandler::UP;
bool InputHandler::LEFT;
bool InputHandler::DOWN;
bool InputHandler::RIGHT;
bool InputHandler::AnyPRESSED;
bool InputHandler::SPACE;

void InputHandler::keyDown(int key){
    AnyPRESSED = true;
    switch(key){
            //LEFT ARROW
        case 356:
            LEFT = true;
            break;
            //LETTER A
        case 97:
            LEFT = true;
            break;
            //UP ARROW
        case 357:
            UP = true;
            break;
            //LETTER W
        case 119:
            UP = true;
            break;
            //RIGHT ARROW
        case 358:
            RIGHT = true;
            break;
            //LETTER D
        case 100:
            RIGHT = true;
            break;
            //DOWN ARROR
        case 359:
            DOWN = true;
            break;
            //LETTER S
        case 115:
            DOWN = true;
            break;
            //SPACE BAR
        case 32:
            SPACE = true;
            break;
    }
}

void InputHandler::keyUp(int key){
    AnyPRESSED = true;
    switch(key){
        case 356:
            LEFT = false;
            break;
        case 357:
            UP = false;
            break;
        case 358:
            RIGHT = false;
            break;
        case 359:
            DOWN = false;
            break;
        case 32:
            SPACE = false;
            break;
            //LETTER S
        case 115:
            DOWN = false;
            break;
            //LETTER D
        case 100:
            RIGHT = false;
            break;
            //LETTER W
        case 119:
            UP = false;
            break;
            //LETTER A
        case 97:
            LEFT = false;
            break;
    }
}
bool InputHandler::getSPACE(){
    return SPACE;
}

bool InputHandler::getUP(){
    return UP;
}

bool InputHandler::getMOUSE1(){
    return false;
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
bool InputHandler::getAnyPRESSED(){
    return AnyPRESSED;
}