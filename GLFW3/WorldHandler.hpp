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
#include "ofMain.h"
#include <fstream>
#include <boost/lexical_cast.hpp>
#include "SpriteHandler.hpp"

class WorldHandler{
public:
        //returns the instance of the handler
    static WorldHandler* getInstance();
    void loadWorld(int i);
    void renderWorld();
private:
    //creation and singleton method blocks
    WorldHandler(){}; //no creation needed
    WorldHandler(WorldHandler const &s){}; // no copy constructor
    WorldHandler& operator=(WorldHandler const &s){}; //no assignment
    //the only instance allowed
    static WorldHandler* instance;
    
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
    int xSize = 0, ySize = 0;
};

#endif /* WorldHandler_hpp */
