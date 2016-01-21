//
//  State.cpp
//  Project2
//
//  Created by William Meaton on 21/01/2016.
//  Copyright © 2016 WillMeaton.uk. All rights reserved.
//

#include "State.hpp"

State* State::currentState = nullptr;

State* State::getCurrentState(){
    return currentState;
}

void State::setState(State* s){
    currentState = s;
}