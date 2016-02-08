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
#include <memory>
enum SPRITE_CODE{
    grass1 = 0,
    grass2 = 1,
    waterDTop = 2,
    waterDLeft = 3,
    waterDRigt = 4,
    waterDBottom = 5,
    waterDTopRight = 6,
    waterDTopLeft = 7,
    waterDBotRight = 8,
    waterDBotLeft = 9,
    stonePath = 10,
    player = 11,
    END_SPRITE = 12,
    SPRITE_SIZE = 64
};

class SpriteHandler{
public:
    //returns the instance of the handler
    static std::shared_ptr<SpriteHandler> getInstance();
    void loadImages();
    std::unique_ptr<Graphics::Image>& get(int i);
    SpriteHandler(){}; //no creation needed

private:
    //creation and singleton method blocks
    SpriteHandler(SpriteHandler const &s){}; // no copy constructor
    //SpriteHandler& operator=(SpriteHandler const &s){}; //no assignment
    //the only instance allowed
    static std::shared_ptr<SpriteHandler> instance;
    
    //actual sprite things
    std::unique_ptr<Graphics::Image> images[SPRITE_CODE::END_SPRITE];
};
#endif /* SpriteHandler_hpp */
