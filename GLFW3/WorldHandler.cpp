//
//  WorldHandler.cpp
//  Project2
//
//  Created by William Meaton on 20/01/2016.
//
//

#include "WorldHandler.hpp"

WorldHandler* WorldHandler::instance;

WorldHandler* WorldHandler::getInstance(){
    if(!instance){
        instance = new WorldHandler;
    }
    return instance;
}

int WorldHandler::getOffSetX(){
    return offSetX;
}

int WorldHandler::getOffSetY(){
    return offSetY;
}

bool WorldHandler::isWorldLoaded(){
    return worldLoaded;
}

bool WorldHandler::isTypesLoaded(){
    return typeLoaded;
}

bool WorldHandler::offSetby(int x, int y){
    //if it's less than the size of the map
    if(offSetX+x < 0 || offSetY+y > 0){
        return false;
    }
    //if it's bigger than the size of the map
    if(offSetX+x >= xMapSize/(windowWidth/SPRITE_CODE::SPRITE_SIZE) ||
       //minus offsetY because it's negative
       (-offSetY)-y >= yMapSize/(windowHeight/SPRITE_CODE::SPRITE_SIZE)){
        return false;
    }
    offSetX += x;
    offSetY += y;
    return true;
}

bool WorldHandler::offSetby(const Math::Vector2D &v){
    //if it's less than the size of the map
    if(offSetX+v.x < 0 || offSetY+v.y > 0){
        return false;
    }
    //if it's bigger than the size of the map
    if(offSetX+v.x >= xMapSize/(windowWidth/SPRITE_CODE::SPRITE_SIZE) ||
       //negative offsetbecase its negative
       (-offSetY)-v.y >= yMapSize/(windowHeight/SPRITE_CODE::SPRITE_SIZE)){
        return false;
    }
    this->offSetX += v.x;
    this->offSetY += v.y;
    return true;
}

void WorldHandler::loadTileTypes(int typeNum){
    const char seperator = ',';
    std::ifstream worldFile("data/tiles"+std::to_string(typeNum)+".csv", std::ios::in); //declare a file stream
    if (worldFile.is_open()) //checks if the file is open??
    {
        std::string str;
        while (getline(worldFile, str)){
            //if it's a / just ignore the entire line
            if(str[0] == '/'){
                continue;
            }
            
            //loop through and push all the tiles into a vector
            std::vector<int> readIntegers; // this will hold the data
            std::string read;
            for(int i = 0; i <= str.length(); i++){
                //find seperators and split the integers
                //this allows for >1 digit ints
                // i >= str.length finds the end of the line
                if(str[i] == seperator || i >= str.length()){
                    int tempInt = atoi(read.c_str());
                    read.clear();
                    readIntegers.push_back(tempInt);
                }else{
                    read += str[i];
                }
            }
            //now push the integers in
            tiles.push_back(Tile(readIntegers[0], readIntegers[1]));
        }
        typeLoaded = true;
    }else{
        typeLoaded = false;
        std::cout << "Tile file failed to load" << std::endl;
    }
}

void WorldHandler::loadWorld(int worldNum){
    if(!typeLoaded){
        this->loadTileTypes(worldNum);
    }
    
    const char seperator = ',';
    std::ifstream worldFile("data/world"+std::to_string(worldNum)+".csv", std::ios::in); //declare a file stream
    if (worldFile.is_open()) //checks if the file is open??
    {
        std::string str;
        while (getline(worldFile, str)){
            //loop through and push all the ints to a vector
            std::string read;
            for(int i = 0; i <= str.length(); i++){
                //find seperators and split the integers
                //this allows for >1 digit ints
                // i >= str.length finds the end of the line
                if(str[i] == seperator || i >= str.length()){
                    xMapSize++;
                    int tempInt = atoi(read.c_str()); // turn into an int
                    read.clear(); // clear the read String for next time
                    //if the tempInt is incorrect or invalid
                    if(tempInt > tiles.size() || tempInt < 0){
                        std::cout << "World failed to load, invalid tile ID";
                        return;
                    }
                    map.push_back(&tiles[tempInt]);
                }else{
                    read += str[i];
                }
            }
            //count how many lines there are
            yMapSize++;
        }
        //xMapSize will end up being xSize*number of lines
        //so fix that
        xMapSize = xMapSize/yMapSize;
        worldLoaded = true;
    }else{
        worldLoaded = false;
        std::cout << "World file failed to load" << std::endl;
    }
}

void WorldHandler::renderWorld(){
    //don't draw if it's not been loaded
    if(!worldLoaded){
        std::cout << "No world loaded" << std::endl;
        return;
    }
    SpriteHandler* temp = SpriteHandler::getInstance();
    //it needs to be abs'd but not the actual value
    int tempOffSetX = offSetX;
    int tempOffSetY = offSetY;
    Math::absolute(tempOffSetY);
    Math::absolute(tempOffSetX);
    //this is so it only loops on the ones that are to be displayed
    //this cuts CPU and GPU strain by a crazy amount
    int minOffSetX = tempOffSetX*(windowWidth/SPRITE_CODE::SPRITE_SIZE);
    int minOffSetY = tempOffSetY*(windowHeight/SPRITE_CODE::SPRITE_SIZE);
    
    int maxOffSetX = (tempOffSetX+1)*(windowWidth/SPRITE_CODE::SPRITE_SIZE);
    int maxOffSetY = (tempOffSetY+1)*(windowHeight/SPRITE_CODE::SPRITE_SIZE);
    
    //check if they're trying to load out of bounds
    if(maxOffSetY > yMapSize || maxOffSetX > xMapSize){
        std::cout << "Map coords out of bounds" << std::endl;
        return;
    }
    //draw the world using the offsets
    for(int i = minOffSetY; i < maxOffSetY; i++){
        for(int j = minOffSetX; j < maxOffSetX; j++){
            //draw the sprites
            temp->get(map[j+i*xMapSize]->textureCode).draw(((j-minOffSetX)*SPRITE_CODE::SPRITE_SIZE), ((i-minOffSetY)*SPRITE_CODE::SPRITE_SIZE), SPRITE_CODE::SPRITE_SIZE, SPRITE_CODE::SPRITE_SIZE);
        }
    }
}