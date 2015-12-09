//
//  Runner.hpp
//  GLFW3
//
//  Created by William Meaton on 09/12/2015.
//  Copyright © 2015 WillMeaton.uk. All rights reserved.
//

#ifndef Runner_hpp
#define Runner_hpp

#include "BaseCore.hpp"
class Runner{
    BaseCore c;
    static float windowWidth, windowHeight;
public:
    Runner(float windowWidth, float windowHeight, BaseCore* c);
};

#endif /* Runner_hpp */
