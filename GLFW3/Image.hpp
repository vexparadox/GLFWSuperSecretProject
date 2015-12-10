//
//  Image.hpp
//  GLFW3
//
//  Created by William Meaton on 10/12/2015.
//  Copyright © 2015 WillMeaton.uk. All rights reserved.
//

#ifndef Image_hpp
#define Image_hpp

#include "SOIL/SOIL.h"
#include "GLFW/glfw3.h"
#include <iostream>

class Image{
    GLuint textureID;
    int w, h;
public:
    Image();
    bool loadImage(const char* name, int w, int h);
    void draw(float x, float y);
};

#endif /* Image_hpp */
