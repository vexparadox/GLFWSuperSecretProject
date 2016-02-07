//
//  Object.hpp
//  Project2
//
//  Created by William Meaton on 19/01/2016.
//
//

#ifndef Object_hpp
#define Object_hpp

#include <stdio.h>
#include "Math.h"
#include "WorldHandler.hpp"
class Object{
    bool visible;
protected:
    Object(bool visible = false, const Graphics::Rect &bounds = Graphics::Rect(0,0,0,0));
    Graphics::Rect bounds;

public:
    virtual void render(){};
    virtual void update(){};
};

#endif /* Object_hpp */
