//
//  main.cpp
//  GLFW3
//
//  Created by William Meaton on 07/12/2015.
//  Copyright © 2015 WillMeaton.uk. All rights reserved.
//

#include <iostream>
#include <SOIL/SOIL.h>
#include "Runner.hpp"
#include "Core.hpp"

int main(void)
{
//    unsigned char* image = SOIL_load_image("image.png", &width, &height, 0, SOIL_LOAD_AUTO);
//    
//    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, image);
//    SOIL_free_image_data(image);
//    glBindTexture(GL_TEXTURE_2D, 0);

    
    
    //start a new runner
    Runner(720, 480, 30, "Title of Window", new Core);
}