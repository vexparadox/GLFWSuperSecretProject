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
#include "Math.h"
#include <iostream>
namespace Graphics{
class Image{
private:
    GLuint textureID;
    int w, h, mipMapLeveCount;
    bool loaded = false;
    GLuint getTextureID();
public:
    Image(){};
    Image(std::string nameInput);
    bool loadImage(std::string nameInput);
    void draw(Math::Vector2D v, float w, float h);
    void draw(float x, float y, float w, float h);
    void draw(Math::Vector2D v);
    void draw(float x, float y);
    int getWidth();
    int getHeight();
    bool grabScreen(float x, float y, float w, float h);
    bool isLoaded();
};
}

#endif /* Image_hpp */
