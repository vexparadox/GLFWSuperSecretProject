//
//  Graphics.hpp
//  GLFW3
//
//  Created by William Meaton on 07/12/2015.
//  Copyright © 2015 WillMeaton.uk. All rights reserved.
//

#ifndef Graphics_hpp
#define Graphics_hpp

#include "Types.h"
#include "GLFW/glfw3.h"

namespace Graphics{
    //Triangles
    void drawTriangle(Triangle& t);
    void drawTriangle(Math::Vector2D v1, Math::Vector2D v2, Math::Vector2D v3);
    void drawTriangle(float x1, float y1, float x2, float y2, float x3, float y3);
    //Rectangles
    void drawRect(Rect& r);
    void drawRect(Math::Vector2D v1, float w, float h);
    void drawRect(float x, float y, float w, float h);
    //Polygons
    void drawPoly(Polygon& p);
    void drawPoly(std::vector<Math::Vector2D>& v);
    
    void setBackground(float r, float g, float b, float a);
    void setBackground(float r, float g, float b);
    void setBackground(Colour c);
}


#endif /* Graphics_hpp */
