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
protected:
    Math::Vector2D scene, tile;
    ScenedObject(Math::Vector2D tile, Math::Vector2D scene, const Graphics::Rect &bounds, bool visible);
};

#endif /* ScenedObject_hpp */
