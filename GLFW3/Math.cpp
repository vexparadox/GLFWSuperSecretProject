//
//  Math.cpp
//  GLFW3
//
//  Created by William Meaton on 08/12/2015.
//  Copyright © 2015 WillMeaton.uk. All rights reserved.
//

#include <stdio.h>
#include "Math.h"
namespace Screen{
Math::Vector2D GlPosition(Math::Vector2D pixelPosition){
        pixelPosition.y = WINDOW_HEIGHT - pixelPosition.y;
        Math::Vector2D screenExtents = Math::Vector2D(WINDOW_WIDTH,WINDOW_HEIGHT) / 2;
        Math::Vector2D GlPosition = pixelPosition - screenExtents;
        GlPosition /= screenExtents;
        return GlPosition;
    }
    
    Math::Vector2D GLPosition(float x, float y){
        return Screen::GlPosition(Math::Vector2D(x, y));
    }
}