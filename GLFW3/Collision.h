//
//  Collision.h
//  Project2
//
//  Created by William Meaton on 26/01/2016.
//  Copyright © 2016 WillMeaton.uk. All rights reserved.
//

#ifndef Collision_h
#define Collision_h
#include "Rect.h"
namespace Math {
    //returns if v3 is inside of v1-v2
    bool isInsideQuad(const Vector2D &v1, const Vector2D &v2, const Vector2D &v3);
    
    bool isInsideQuad(const Graphics::Rect &r, const Vector2D &v3);
    
    bool isInsideQuad(float x1, float y1, float x2, float y2, float x3, float y3);
}

#endif /* Collision_h */
