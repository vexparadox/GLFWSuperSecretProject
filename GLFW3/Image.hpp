//
//  Image.hpp
//  GLFW3
//
//  Created by William Meaton on 10/12/2015.
//  Copyright © 2015 WillMeaton.uk. All rights reserved.
//

#ifndef Image_hpp
#define Image_hpp

#include <SOIL/SOIL.h>
#include <GLFW/glfw3.h>
#include <iostream>

class Image{
private:
    GLuint textureID;
    int w, h;
    bool loaded = false;
    GLuint getTextureID();
public:
    Image(){};
    Image(std::string nameInput, int w, int h);
    bool loadImage(std::string nameInput, int w, int h);
    void draw(float x, float y);
    bool grabScreen(float x, float y, float w, float h);
    bool isLoaded();
};

#endif /* Image_hpp */
