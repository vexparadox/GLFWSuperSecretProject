//
//  SpriteHandler.hpp
//  Project2
//
//  Created by William Meaton on 20/01/2016.
//
//

#ifndef SpriteHandler_hpp
#define SpriteHandler_hpp

#include <stdio.h>
#include "CoreMain.h"
enum SPRITE_CODE{
    player = 0,
    unused1 = 1,
    waterDown = 2,
    unusded2 = 3,
    waterTopRight = 4,
    waterTopLeft = 5,
    waterLeft = 6,
    waterTop = 7,
    grass1 = 8,
    grass2 = 9,
    waterRight = 10,
    unused3 = 11,
    waterBottomRight = 12,
    waterBottomLeft = 13,
    END_SPRITE = 14,
    SPRITE_SIZE = 64
};

class SpriteHandler{
public:
    //returns the instance of the handler
    static SpriteHandler* getInstance();
    
    void loadImages();
    Graphics::Image& get(int i);
private:
    //creation and singleton method blocks
    SpriteHandler(){}; //no creation needed
    SpriteHandler(SpriteHandler const &s){}; // no copy constructor
    //SpriteHandler& operator=(SpriteHandler const &s){}; //no assignment
    //the only instance allowed
    static SpriteHandler* instance;
    
    //actual sprite things
    Graphics::Image images[SPRITE_CODE::END_SPRITE];
};
#endif /* SpriteHandler_hpp */
