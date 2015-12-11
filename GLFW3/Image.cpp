//
//  Image.cpp
//  GLFW3
//
//  Created by William Meaton on 10/12/2015.
//  Copyright © 2015 WillMeaton.uk. All rights reserved.
//

#include "Image.hpp"
bool Image::loadImage(std::string nameInput, int w, int h){
    std::string temp = "../../data/" + nameInput;
    const char* name = temp.c_str();
    //check if it's already loaded, if so load into the same texture point
    if(!loaded){
    textureID = SOIL_load_OGL_texture (name,
                                    SOIL_LOAD_AUTO,
                                    SOIL_CREATE_NEW_ID,
                                    SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
                                       );

    }else{
        GLuint temp = SOIL_load_OGL_texture (name,
                                           SOIL_LOAD_AUTO,
                                           textureID,
                                           SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
                                           );
        //if the load failed then return a fail
        if(temp == 0){
            return false;
        }
    }
    if(textureID != 0){
        this->w = w;
        this->h = h;
        loaded = true;
        return true;
    }
    return false;
}

void Image::draw(float x, float y){
    if(textureID == 0 || !loaded){
        std::cout << "No image has been loaded" << std::endl;
        return;
    }
    glBindTexture(GL_TEXTURE_2D, textureID);
    glEnable(GL_TEXTURE_2D);
    glBegin(GL_QUADS);
    glTexCoord2d(0,0); glVertex2f(x, y+h);
    //bottom left
    glTexCoord2d(0,1); glVertex2f(x, y);
    //top left
    glTexCoord2d(1,1); glVertex2f(x+w, y);
    //top right
    glTexCoord2d(1,0); glVertex2f(x+w, y+h);
    //bottom right
    glEnd();
}

bool Image::grabScreen(float x, float y, float w, float h){
    return SOIL_save_screenshot
    (
     "save.bmp",
     SOIL_SAVE_TYPE_BMP,
     0, 0, 1024, 768
     );
}

bool Image::isLoaded(){
    return loaded;
}

GLuint Image::getTextureID(){
    return textureID;
}