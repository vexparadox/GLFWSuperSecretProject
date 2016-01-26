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
    
    float triangleArea(const Vector2D &v1, const Vector2D &v2, const Vector2D &v3){
        float det = 0.0f;
        det = ((v1.x - v3.x) * (v2.y - v3.y)) - ((v2.x - v3.x) * (v1.y - v3.y));
        return (det / 2.0f);
    }
    
    float triangleArea(const Graphics::Triangle &t){
        return triangleArea(t.v1, t.v2, t.v3);
    }
    
    bool isInsideTriangle(const Vector2D &point, const Vector2D &v1, const Vector2D &v2, const Vector2D &v3){
        float total = triangleArea(point, v2, v3);
        float area1 = triangleArea(point, v2, v3);
        float area2 = triangleArea(point, v1, v3);
        float area3 = triangleArea(point, v1, v2);
        if((area1 + area2 + area3) > total){
            return false;
        }else{
            return true;
        }
    }
    
    bool isInsideTriangle(const Vector2D &point, const Graphics::Triangle &t){
        return isInsideTriangle(point, t.v1, t.v2, t.v3);
    }
    
}