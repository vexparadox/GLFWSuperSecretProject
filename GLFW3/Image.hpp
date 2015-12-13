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
#include <GLFW/glfw3.h>
#include <iostream>

class Image{
    GLuint textureID;
    int w, h;
    bool loaded = false;
public:
    Image(){};
    bool loadImage(std::string nameInput, int w, int h);
    void draw(float x, float y);
    bool grabScreen(float x, float y, float w, float h);
    bool isLoaded();
    GLuint getTextureID();
};

#endif /* Image_hpp */
