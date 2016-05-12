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

#endif /* Entity_hpp */

class Entity{
    bool init();
public:
    Entity();
    Entity(const Math::Vector2D& pos);
};