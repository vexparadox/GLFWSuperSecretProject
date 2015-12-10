//
//  Graphics.cpp
//  GLFW3
//
//  Created by William Meaton on 07/12/2015.
//  Copyright © 2015 WillMeaton.uk. All rights reserved.
//

#include "Graphics.hpp"
namespace Graphics{
    void drawTriangle(Triangle& t){
        drawTriangle(t.v1, t.v2, t.v3);
    }

    void drawTriangle(Math::Vector2D v1, Math::Vector2D v2, Math::Vector2D v3){
        glBegin(GL_TRIANGLES);
        glVertex3f(v1.x, v1.y, 0.f);
        glVertex3f(v2.x, v2.y, 0.f);
        glVertex3f(v3.x, v3.y, 0.f);
        glEnd();
    }

    void drawTriangle(float x1, float y1, float x2, float y2, float x3, float y3){
        Graphics::drawTriangle(Math::Vector2D(x1, y1), Math::Vector2D(x2, y2), Math::Vector2D(x3, y3));
    }

    void drawRect(float x, float y, float w, float h){
        drawRect(Math::Vector2D(x, y), w, h);
    }

    void drawRect(Math::Vector2D v, float w, float h){
        glBegin(GL_QUADS);
        glVertex3f(v.x, v.y, 0.0f);
        //top left
        glVertex3f(v.x, v.y+h, 0.0f );
        //bottom left
        glVertex3f(v.x+w, v.y+h, 0.0f );
        //bottom right
        glVertex3f(v.x+w, v.y, 0.0f );
        //top right
        glEnd( );
    
    }
    
    void drawPoly(Polygon& p){
        glBegin(GL_POLYGON);
        for(auto points : p.getVerticies()){
            glVertex3f(points.x, points.y, 0.0f);
        }
        glEnd();
    }
    
    void drawPoly(std::vector<Math::Vector2D>& v){
        glBegin(GL_POLYGON);
        for(auto points : v){
            glVertex3f(points.x, points.y, 0.0f);
        }
        glEnd();
    }
    
    void setBackground(float r, float g, float b, float a){
        glClearColor(r/255, g/255, b/255, a/255);
    }
    
    void setBackground(float r, float g, float b){
        setBackground(r, g, b, 0);
    }
    
    void setBackground(Colour c){
        setBackground(c.r, c.g, c.b, c.a);
    }
}