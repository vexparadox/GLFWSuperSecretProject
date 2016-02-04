//
//  ScenedObject.hpp
//  Project2
//
//  Created by William Meaton on 04/02/2016.
//  Copyright © 2016 WillMeaton.uk. All rights reserved.
//

#ifndef ScenedObject_hpp
#define ScenedObject_hpp

#include <stdio.h>
#include "Math.h"
#include "Object.hpp"

class ScenedObject : public Object{
    Math::Vector2D scene, tile;
    ScenedObject(Math::Vector2D scene, Math::Vector2D tile, bool visible);
};

#endif /* ScenedObject_hpp */
