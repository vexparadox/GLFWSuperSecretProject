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
    tile0 = 0,
    tile1 = 1,
    tile2 = 2,
    tile3 = 3,
    END_SPRITE = 4,
    SPRITE_SIZE = 50
};

class SpriteHandler{
public:
    //returns the instance of the handler
    static SpriteHandler* getInstance();
    
    void loadImages();
    Graphics::Image get(int i);
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
