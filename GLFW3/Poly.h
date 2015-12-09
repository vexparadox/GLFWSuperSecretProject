//
//  Poly.h
//  GLFW3
//
//  Created by William Meaton on 08/12/2015.
//  Copyright © 2015 WillMeaton.uk. All rights reserved.
//

#ifndef Poly_h
#define Poly_h
#include <vector>
#include "Math.h"
#include "Graphics.hpp"
class Polygon{
private:
    std::vector<Math::Vector2D> v;
public:
    Polygon();
    ~Polygon();
    void addVertex(Math::Vector2D v){
        this->v.push_back(v);
    }
    
    void clear(){
        this->v.clear();
    }
    
    std::vector<Math::Vector2D> getVerticies(){
        return v;
    }
    
};

#endif /* Poly_h */
