//
//  Collision.cpp
//  Project2
//
//  Created by William Meaton on 26/01/2016.
//  Copyright © 2016 WillMeaton.uk. All rights reserved.
//

#include "Collision.h"

namespace Math {
    //returns if v3 is inside of v1-v2
    bool isInsideQuad(const Vector2D &v1, const Vector2D &v2, const Vector2D &v3){
        if(v3.x > v1.x && v3.x < v2.x && v3.y > v1.y && v3.y < v2.y){
            return true;
        }
        return false;
    }
    
    bool isInsideQuad(const Graphics::Rect &r, const Vector2D &v3){
        return isInsideQuad(r.v, Vector2D(r.w, r.h), v3);
    }
    
    bool isInsideQuad(float x1, float y1, float x2, float y2, float x3, float y3){
        return isInsideQuad(Vector2D(x1, x2), Vector2D(x2, y2), Vector2D(x3, y3));
    }
    
}