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
    Colour(){
        r = 0;
        g = 0;
        b = 0;
        a = 0;
    }
private:
    inline void colourAssign(float &c, float input){
        if(input > 255){
            c = 255;
            return;
        }
        if(input < 0){
            c = 0;
            return;
        }
        c = input;
    }
    
    inline Colour operator- (const Colour& c){
        Colour temp;
        colourAssign(temp.r, (this->r - c.r));
        colourAssign(temp.g, (this->g - c.g));
        colourAssign(temp.b, (this->b - c.b));
        colourAssign(temp.a, (this->a - c.a));
        return temp;
    }
    
    friend inline void operator-= (Colour& c1, const Colour& c2){
        c1 = c1-c2;
        return;
    }
    
    inline Colour operator+ (const Colour& c){
        Colour temp;
        colourAssign(temp.r, (this->r + c.r));
        colourAssign(temp.g, (this->g + c.g));
        colourAssign(temp.b, (this->b + c.b));
        colourAssign(temp.a, (this->a + c.a));
        return temp;
    }
    
    friend inline void operator+= (Colour& c1, const Colour& c2){
        c1 = c1+c2;
        return;
    }
};

#endif /* Colour_h */
