//
//  Entity.cpp
//  closedFrameworks
//
//  Created by William Meaton on 12/05/2016.
//  Copyright © 2016 WillMeaton.uk. All rights reserved.
//

#include "Entity.hpp"

Entity::Entity(){
    this->init();
}

Entity::Entity(const Math::Vector2D& pos){
    this->init();
}

bool Entity::init(){
    
    return true;
}