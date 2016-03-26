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
#include <vector>
#include "Math.h"

namespace Graphics{
    //Triangles
    void drawTriangle(const Triangle &t);
    void drawTriangle(const Math::Vector2D &v1, const Math::Vector2D &v2, const Math::Vector2D &v3);
    void drawTriangle(float x1, float y1, float x2, float y2, float x3, float y3);
    //Rectangles
    void drawRect(const Rect &r);
    void drawRect(const Math::Vector2D &v1, float w, float h);
    void drawRect(float x, float y, float w, float h);
    //Polygons
    void drawPoly(Polygon &p);
    void drawPoly(std::vector<Math::Vector2D>& v);
    
    //gets the pixel data between two points, (x,y) and (w,h)
    std::vector<unsigned char> getScreenData(int x, int y, int w, int h);
    
    //set the background to be flushed
    void setBackground(float r, float g, float b, float a);
    void setBackground(float r, float g, float b);
    void setBackground(const Colour &c);
    
    //push and pop a new matrix
    void pushMatrix();
    void popMatrix();
    
    //translate the current pushed matrix
    void translate(float x, float y, float z);
    void translate(float x, float y);
    void translate(const Math::Vector2D& v);
    void translate(const Math::Vector3D& v);
}


#endif /* Graphics_hpp */
