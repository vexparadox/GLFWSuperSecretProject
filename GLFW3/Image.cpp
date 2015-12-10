//
//  Image.cpp
//  GLFW3
//
//  Created by William Meaton on 10/12/2015.
//  Copyright © 2015 WillMeaton.uk. All rights reserved.
//

#include "Image.hpp"


Image::Image(){
}

bool Image::loadImage(const char *name, int w, int h){
    textureID = SOIL_load_OGL_texture (name,
                                    SOIL_LOAD_AUTO,
                                    SOIL_CREATE_NEW_ID,
                                    SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
                                       );
    if(textureID != 0){
        this->w = w;
        this->h = h;
        return true;
    }
    return false;
}

void Image::draw(float x, float y){
    if(textureID == 0){
        std::cout << "No image has been loaded" << std::endl;
        return;
    }
    glBindTexture(GL_TEXTURE_2D, textureID);
    glEnable(GL_TEXTURE_2D);
    glBegin(GL_QUADS);
    glTexCoord2d(0,0); glVertex2f(x, y+h);
    glTexCoord2d(0,1); glVertex2f(x, y);
    glTexCoord2d(1,1); glVertex2f(x+w, y);
    glTexCoord2d(1,0); glVertex2f(x+w, y+h);
    glEnd();
}