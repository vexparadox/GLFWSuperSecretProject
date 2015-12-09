//
//  main.cpp
//  GLFW3
//
//  Created by William Meaton on 07/12/2015.
//  Copyright © 2015 WillMeaton.uk. All rights reserved.
//

#include <iostream>
#include "Runner.hpp"
#include "Core.hpp"

int main(void)
{
    //start a new runner
    Runner(720, 480, new Core);
}