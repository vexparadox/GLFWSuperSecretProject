//
//  Math.h
//  GLFW3
//
//  Created by William Meaton on 07/12/2015.
//  Copyright © 2015 WillMeaton.uk. All rights reserved.
//

#ifndef Math_h
#define Math_h

#include "Vector2D.h"
#include "Vector3D.h"

namespace Screen{
    const int WINDOW_HEIGHT = 480;
    const int WINDOW_WIDTH = 720;
    Math::Vector2D GlPosition(Math::Vector2D pixelPosition);
    Math::Vector2D GLPosition(float x, float y);
}

#endif /* Math_h */
