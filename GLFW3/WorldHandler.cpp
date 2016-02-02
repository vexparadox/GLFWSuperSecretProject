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

void WorldHandler::offSetby(int x, int y){
    offSetX += x;
    offSetY += y;
}

void WorldHandler::offSetby(const Math::Vector2D &v){
    this->offSetX += v.x;
    this->offSetY += v.y;
}

void WorldHandler::loadWorld(int worldNum){
    std::ifstream worldFile("data/world"+std::to_string(worldNum)+".txt", std::ios::in); //declare a file stream
    if (worldFile.is_open()) //checks if the file is open??
    {
        std::string str; //declare a string for storage
        while (getline(worldFile, str)){ //get a line from the file, put in the string
            //loop through and push all the ints to a vector
            for(int i = 0; i <= str.length(); i+=2){
                //convert the string into an int
                int tempInt = (int)str[i] - 48;
                map.push_back(Tile(tempInt));
                xMapSize++;
            }
            //count how many lines there are
            yMapSize++;
        }
        //xMapSize will end up being xSize*number of lines
        //so fix that
        xMapSize = xMapSize/yMapSize;
    }else{
        std::cout << "World file failed to load";
    }
}

void WorldHandler::renderWorld(){
    SpriteHandler* temp = SpriteHandler::getInstance();
    //this is so it only loops on the ones that are to be displayed
    
    int minOffSetX = offSetX*(windowWidth/SPRITE_CODE::SPRITE_SIZE);
    int minOffSetY = offSetY*(windowHeight/SPRITE_CODE::SPRITE_SIZE);
    
    int maxOffSetX = (offSetX+1)*(windowWidth/SPRITE_CODE::SPRITE_SIZE);
    int maxOffSetY = (offSetY+1)*(windowHeight/SPRITE_CODE::SPRITE_SIZE);
    
    
    for(int i = minOffSetY; i < maxOffSetY; i++){
        for(int j = minOffSetX; j < maxOffSetX; j++){
            //draw the sprites
            temp->get(map[j+i*xMapSize].textureCode).draw((j*SPRITE_CODE::SPRITE_SIZE), (i*SPRITE_CODE::SPRITE_SIZE), SPRITE_CODE::SPRITE_SIZE, SPRITE_CODE::SPRITE_SIZE);
        }
    }
}