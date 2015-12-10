//
//  Core.cpp
//  GLFW3
//
//  Created by William Meaton on 08/12/2015.
//  Copyright © 2015 WillMeaton.uk. All rights reserved.
//

#include "Core.hpp"

void Core::setup(){
    std::cout << "SETUP BRO";
    tex_2d = SOIL_load_OGL_texture (
                                    "/Users/williammeaton/Desktop/GLFW3/img.jpg",
                                    SOIL_LOAD_AUTO,
                                    SOIL_CREATE_NEW_ID,
                                    SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
                                    );
    std::cout << tex_2d;
}

void Core::update(){
    
}

void Core::draw(){
    float x, y;
    int w, h;
    x = 0;
    y = 0;
    w = 200;
    h = 200;

    glColor3f(0.0f,0.f,0.f);
    glBindTexture(GL_TEXTURE_2D, tex_2d);
    glEnable(GL_TEXTURE_2D);
    glBegin(GL_QUADS);
    glTexCoord2d(0,0);        glVertex3f(x+w, y+h, 0);
    glTexCoord2d(0,1);        glVertex3f(x+w, y, 0);
    glTexCoord2d(1,1);        glVertex3f(x+w, y+h, 0);
    glTexCoord2d(1,0);        glVertex3f(x, y, 0);
    glEnd();
}
