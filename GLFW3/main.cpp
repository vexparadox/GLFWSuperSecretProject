//
//  main.cpp
//  GLFW3
//
//  Created by William Meaton on 07/12/2015.
//  Copyright © 2015 WillMeaton.uk. All rights reserved.
//
#include "Runner.hpp"
#include "Core.hpp"

int main(int argc, char *argv[])
{
    //start a new runner with the constructor
    //Runner(int width, int height, int frameRate, const char* title, new Core);
    Runner(1280, 832, 60, "Yet to be titled", new Core);
}