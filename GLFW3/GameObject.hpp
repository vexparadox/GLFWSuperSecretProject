//
//  GameObject.hpp
//  Project2
//
//  Created by William Meaton on 19/01/2016.
//
//

#ifndef GameObject_hpp
#define GameObject_hpp

#include <stdio.h>
#include "CoreMain.h"

class GameObject{
protected:
    Math::Vector2D position;
    bool visible;
    GameObject(Math::Vector2D position, bool visible);
    GameObject(float x, float y, bool visible);
public:
    virtual void render(){};
};

#endif /* GameObject_hpp */
