//
//  Runner.cpp
//  GLFW3
//
//  Created by William Meaton on 09/12/2015.
//  Copyright © 2015 WillMeaton.uk. All rights reserved.
//

#include "Runner.hpp"

Runner::Runner(float windowWidth, float windowHeight, BaseCore* c){
    this->c = *c;
    
    GLFWwindow* window = c->getWindow();
    glfwSetErrorCallback(c->error_callback);
    if (!glfwInit()){
        exit(EXIT_FAILURE);
    }
    
    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
    window = glfwCreateWindow(Screen::WINDOW_WIDTH, Screen::WINDOW_HEIGHT, "Simple example", NULL, NULL);
    
    if (!window)
    {
        glfwTerminate();
        exit(EXIT_FAILURE);
    }
    glfwMakeContextCurrent(window);
    glfwSwapInterval(1);
    glfwSetKeyCallback(window, c->key_callback);
    c->setup();
    while (!glfwWindowShouldClose(window))
    {
        int width, height;
        glfwGetFramebufferSize(window, &width, &height);
        glViewport(0, 0, width, height);
        glClear(GL_COLOR_BUFFER_BIT);
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        glOrtho(0.f, windowWidth, windowWidth, 0.f, 0.f, 1.f);
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
        int iconified = glfwGetWindowAttrib(window, GLFW_ICONIFIED);
        if(iconified != 1){
            c->update();
            c->draw();
        }
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    glfwDestroyWindow(window);
    glfwTerminate();
    exit(EXIT_SUCCESS);
}