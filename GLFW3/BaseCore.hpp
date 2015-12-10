//
//  BaseCore.hpp
//  GLFW3
//
//  Created by William Meaton on 09/12/2015.
//  Copyright © 2015 WillMeaton.uk. All rights reserved.
//

#ifndef BaseCore_hpp
#define BaseCore_hpp

#include <stdio.h>
#include <GLFW/glfw3.h>
#include <SOIL/SOIL.h>
#include <iostream>
#include <stdlib.h>
#include "Graphics.hpp"

class BaseCore{
private:
    GLFWwindow* window;
public:
    virtual ~BaseCore(){};
    virtual void draw(){};
    virtual void setup(){};
    virtual void update(){};
    
    static void error_callback(int error, const char* description);
    static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
    GLFWwindow* getWindow();
};

#endif /* BaseCore_hpp */
