//
//  Colour.h
//  GLFW3
//
//  Created by William Meaton on 10/12/2015.
//  Copyright © 2015 WillMeaton.uk. All rights reserved.
//

#ifndef Colour_h
#define Colour_h

class Colour{
public:
    float r, g, b, a;
    Colour(float r, float g, float b, float a) {
        colourAssign(this->r, r);
        colourAssign(this->g, g);
        colourAssign(this->b, b);
        colourAssign(this->a, a);
    }
private:
    inline void colourAssign(float c, float input){
        if(input > 255){
            c = 255;
            return;
        }
        if(input < 0){
            c = 0;
            return;
        }
    }
};

#endif /* Colour_h */
