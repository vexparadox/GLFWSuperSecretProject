//
//  BaseCore.cpp
//  GLFW3
//
//  Created by William Meaton on 09/12/2015.
//  Copyright © 2015 WillMeaton.uk. All rights reserved.
//

#include "BaseCore.hpp"


GLFWwindow* BaseCore::getWindow(){
    return window;
}

void BaseCore::error_callback(int error, const char* description){
    fputs(description, stderr);
}
void BaseCore::key_callback(GLFWwindow* window, int key, int scancode, int action, int mods){
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS){
        glfwSetWindowShouldClose(window, GL_TRUE);
    }
}