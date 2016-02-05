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

class Object{
    bool visible;
protected:
    Object(const Graphics::Rect &bounds, bool visible = false);
    Graphics::Rect bounds;

public:
    virtual void render(){};
    virtual void update(){};
};

#endif /* Object_hpp */
