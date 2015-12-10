//
//  Runner.cpp
//  GLFW3
//
//  Created by William Meaton on 09/12/2015.
//  Copyright © 2015 WillMeaton.uk. All rights reserved.
//

#include "Runner.hpp"
float Runner::windowWidth = 0;
float Runner::windowHeight = 0;

Runner::Runner(float windowWidth, float windowHeight, int frameRate,const char* title,BaseCore* c){
    Runner::windowWidth = windowWidth;
    Runner::windowHeight = windowHeight;
    //assign the core to the pointer
    this->c = c;
    
    //get the window from the core
    GLFWwindow* window = c->getWindow();
    //sets the event call back method in basecore
    //set the error method in basecore
    glfwSetErrorCallback(error_callback);
    //if it fails then exit
    if (!glfwInit()){
        exit(EXIT_FAILURE);
    }
    //stop the window from being resizeable
    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
    //create the window using the height and stuff
    window = glfwCreateWindow(windowWidth, windowHeight, title, NULL, NULL);
    //set a userpointer for the window to this version of Runner
    glfwSetWindowUserPointer(window, this);
    //set the key_callback method
    glfwSetKeyCallback(window, key_callback);
    //if the window is dead, stop the program
    if (!window)
    {
        glfwTerminate();
        exit(EXIT_FAILURE);
    }
    //sets the context to the window
    glfwMakeContextCurrent(window);
    //sets the intervals of buffer swaps
    glfwSwapInterval(1);
    //call setup for first time run
    c->setup();
    //the game loop
    while (!glfwWindowShouldClose(window))
    {
        if(fps(frameRate)){
            continue;
        }
        int width, height;
        //set view port
        glfwGetFramebufferSize(window, &width, &height);
        glViewport(0, 0, width, height);
        //clear the buffer
        glClear(GL_COLOR_BUFFER_BIT);
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        //set the ortho to pixels so it can be used like processing
        glOrtho(0.f, windowWidth, windowWidth, 0.f, 0.f, 1.f);
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
        //call update and then draw if the window isn't iconified
        int iconified = glfwGetWindowAttrib(window, GLFW_ICONIFIED);
        if(iconified != 1){
            //update then draw
            c->update();
            c->draw();
        }
        //swap the buffers
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    glfwDestroyWindow(window);
    glfwTerminate();
    exit(EXIT_SUCCESS);
}

bool Runner::fps(int framerate)
{
    currentTime = glfwGetTime();
    
    if(currentTime - lastTime >= 1.0 / framerate)
    {
        lastTime = currentTime;
        return true;
    }
    return false;
}

void Runner::error_callback(int error, const char* description){
    fputs(description, stderr);
}
void Runner::key_callback(GLFWwindow* window, int key, int scancode, int action, int mods){
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS){
        glfwSetWindowShouldClose(window, GL_TRUE);
        return;
    }
    void* data = glfwGetWindowUserPointer(window);
    Runner* r = static_cast<Runner*>(data);
    if(action == GLFW_PRESS){
        r->c->keyPressed(key);
    }
}
