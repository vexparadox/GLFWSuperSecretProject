//
//  GameObject.hpp
//  Project2
//
//  Created by William Meaton on 19/01/2016.
//
//

#ifndef GameObject_hpp
#define GameObject_hpp

#include <stdio.h>
#include "ofMain.h"

class GameObject{
protected:
    ofPoint position;
    bool visible;
    GameObject(ofPoint position, bool visible);
    GameObject(float x, float y, bool visible);
    virtual void render();
    
};

#endif /* GameObject_hpp */
