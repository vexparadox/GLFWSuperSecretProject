//
//  Entity.hpp
//  closedFrameworks
//
//  Created by William Meaton on 12/05/2016.
//  Copyright © 2016 WillMeaton.uk. All rights reserved.
//

#ifndef Entity_hpp
#define Entity_hpp

#include <stdio.h>
#include "Math.h"
#include "Transform.hpp"

#endif /* Entity_hpp */

class Entity{
    //a list of components
    std::vector<Component*> components;
public:
    //constructors
    Entity();
    Entity(const Math::Vector2D& pos);
    //add a new component
    void addComponent(Component*);
};