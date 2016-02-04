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
#include "Object.hpp"

class GameObject : public Object{
protected:
    Math::Vector2D position, nextPosition;
    bool visible;
    GameObject(const Math::Vector2D &position, bool visible);
    GameObject(float x, float y, bool visible);
    virtual ~GameObject(){};
public:
    const Math::Vector2D& getPosition();
    void setPosition(const Math::Vector2D &v);
    void setPosition(const float &x, const float &y);
    
};

#endif /* GameObject_hpp */
