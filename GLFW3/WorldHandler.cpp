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

bool WorldHandler::isLoaded(){
    return loaded;
}

void WorldHandler::offSetby(int x, int y){
    offSetX += x;
    offSetY += y;
    std::cout << offSetX <<  " " << offSetY << std::endl;
}

void WorldHandler::offSetby(const Math::Vector2D &v){
    this->offSetX += v.x;
    this->offSetY += v.y;
}

void WorldHandler::loadWorld(int worldNum){
    const char seperator = ',';
    std::ifstream worldFile("data/world"+std::to_string(worldNum)+".txt", std::ios::in); //declare a file stream
    if (worldFile.is_open()) //checks if the file is open??
    {
        std::string str; //declare a string for storage
        while (getline(worldFile, str)){ //get a line from the file, put in the string
            //loop through and push all the ints to a vector
            std::string read;
            for(int i = 0; i <= str.length(); i++){
                //find seperators and split the integers
                //this allows for >1 digit ints
                // i >= str.length finds the end of the line
                if(str[i] == seperator || i >= str.length()){
                    xMapSize++;
                    int tempInt = atoi(read.c_str());
                    read.clear();
                    map.push_back(Tile(tempInt));
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
        loaded = true;
    }else{
        loaded = false;
        std::cout << "World file failed to load";
    }
}

void WorldHandler::renderWorld(){
    //don't draw if it's not been loaded
    if(!loaded){
        std::cout << "No world loaded";
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
        std::cout << "Map coords out of bounds";
        return;
    }
    //draw the world using the offsets
    for(int i = minOffSetY; i < maxOffSetY; i++){
        for(int j = minOffSetX; j < maxOffSetX; j++){
            //draw the sprites
            temp->get(map[j+i*xMapSize].textureCode).draw(((j-minOffSetX)*SPRITE_CODE::SPRITE_SIZE), ((i-minOffSetY)*SPRITE_CODE::SPRITE_SIZE), SPRITE_CODE::SPRITE_SIZE, SPRITE_CODE::SPRITE_SIZE);
        }
    }
}