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
    bool offSetby(int x, int y);
    bool offSetby(const Math::Vector2D &v);
    void loadTileTypes(int typeNum);
    int getOffSetX();
    int getOffSetY();
    int windowWidth, windowHeight;
    bool isWorldLoaded();
    bool isTypesLoaded();
private:
    //creation and singleton method blocks
    WorldHandler(){}; //no creation needed
    WorldHandler(WorldHandler const &s){}; // no copy constructor
    //WorldHandler& operator=(WorldHandler const &s){}; //no assignment
    //the only instance allowed
    static WorldHandler* instance;
    
    int offSetX = 0, offSetY = 0;
    bool worldLoaded = false, typeLoaded = false;
    //private class to the world handler
    class Tile{
    public:
        Tile(int tc, bool solid){
            this->textureCode = tc;
            this->solid = solid;
        }
        Tile(int tc){
            this->textureCode = tc;
        }
        int textureCode;
        bool solid = false;
    };
    
    //the map
    std::vector<Tile*> map;
    std::vector<Tile> tiles;
    int xMapSize = 0, yMapSize = 0;
};

#endif /* WorldHandler_hpp */
