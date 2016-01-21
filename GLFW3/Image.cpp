//
//  Image.cpp
//  GLFW3
//
//  Created by William Meaton on 10/12/2015.
//  Copyright © 2015 WillMeaton.uk. All rights reserved.
//

#include "Image.hpp"
namespace Graphics{
Image::Image(std::string name){
    this->loadImage(name);
}

bool Image::loadImage(std::string nameInput){
    std::string temp = "data/" + nameInput;
    const char* name = temp.c_str();
    //check if it's already loaded, if so load into the same texture point
    if(!loaded){
        glEnable(GL_TEXTURE_2D);
        
        GLuint texture_id;
        glGenTextures(1, &texture_id);
        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D, texture_id);
        
        unsigned char* imageDataPtr =SOIL_load_image(name, &this->w, &this->h, 0, SOIL_LOAD_RGBA);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, this->w, this->h, 0, GL_RGBA, GL_UNSIGNED_BYTE, imageDataPtr);
        glEnd();
        SOIL_free_image_data(imageDataPtr);
        this->textureID = texture_id;
    }
//    }else{
//        GLuint temp = SOIL_load_OGL_texture (name,
//                                           SOIL_LOAD_AUTO,
//                                           textureID,
//                                           SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB);
//        //if the load failed then return a fail
//        if(temp == 0){
//            return false;
//        }
//    }
    if(textureID != 0){
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
    glTexCoord2d(0, 1); glVertex2f(x, y+50);
    //bottom left
    glTexCoord2d(0, 0); glVertex2f(x,y);
    //top left
    glTexCoord2d(1, 0); glVertex2f(x+50, y);
    //top right
    glTexCoord2d(1, 1); glVertex2f(x+50, y+50);
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
 
    int Image::getHeight(){
        return h;
    }
    
    int Image::getWidth(){
        return w;
    }
    
}