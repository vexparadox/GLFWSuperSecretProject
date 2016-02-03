//
//  WorldHandler.hpp
//  Project2
//
//  Created by William Meaton on 20/01/2016.
//
//

#ifndef WorldHandler_hpp
#define WorldHandler_hpp

#include <stdio.h>
#include <vector>
#include "coreMain.h"
#include <fstream>
#include "SpriteHandler.hpp"
#include "InputHandler.hpp"

class WorldHandler{
public:
        //returns the instance of the handler
    static WorldHandler* getInstance();
    void loadWorld(int i);
    void renderWorld();
    void offSetby(int x, int y);
    void offSetby(const Math::Vector2D &v);
    int getOffSetX();
    int getOffSetY();
    int windowWidth, windowHeight;
    bool isLoaded();
private:
    //creation and singleton method blocks
    WorldHandler(){}; //no creation needed
    WorldHandler(WorldHandler const &s){}; // no copy constructor
    //WorldHandler& operator=(WorldHandler const &s){}; //no assignment
    //the only instance allowed
    static WorldHandler* instance;
    
    int offSetX = 0, offSetY = 0;
    bool loaded = false;
    //private class to the world handler
    class Tile{
    public:
        Tile(int tc){
            this->textureCode = tc;
        }
        int textureCode;
        int damage = 0;
    };
    
    //the map
    std::vector<Tile> map;
    int xMapSize = 0, yMapSize = 0;
};

#endif /* WorldHandler_hpp */
