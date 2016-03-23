//
//  Rect.h
//  GLFW3
//
//  Created by William Meaton on 07/12/2015.
//  Copyright © 2015 WillMeaton.uk. All rights reserved.
//

#ifndef Rect_h
#define Rect_h

#include "Vector2D.h"
namespace Graphics{
class Rect{
public:
    Math::Vector2D v;
    float w, h;
    Rect(const Math::Vector2D &v1, float w, float h){
        this->v = v1;
        this->w = w;
        this->h = h;
    }
    
    Rect(float x, float y, float w, float h){
        this->v = Math::Vector2D(x, y);
        this->w = w;
        this->h = h;
    }
    
    void set(const Math::Vector2D &v, float w, float h){
        this->v = v;
        this->w = w;
        this->h = h;
    }
    
    void set(float x, float y, float w, float h){
        this->set(Math::Vector2D(x, y), w, h);
    }
};
}

#endif /* Rect_h */
