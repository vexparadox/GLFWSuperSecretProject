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

void WorldHandler::offSetXby(int a){
    offSetX += a;
}

void WorldHandler::offSetYby(int a){
    offSetY += a;
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
                xSize++;
            }
            //count how many lines there are
            ySize++;
        }
        //xSize will end up being xSize*number of lines
        //so fix that
        xSize = xSize/ySize;
    }else{
        std::cout << "World file failed to load";
    }
}

void WorldHandler::renderWorld(){
    SpriteHandler* temp = SpriteHandler::getInstance();
    for(int i = 0; i < ySize; i++){
        for(int j = 0; j < xSize; j++){
            temp->get(map[j+i*xSize].textureCode).draw((j*SPRITE_CODE::SPRITE_SIZE)+offSetX, (i*SPRITE_CODE::SPRITE_SIZE)+offSetY, SPRITE_CODE::SPRITE_SIZE, SPRITE_CODE::SPRITE_SIZE);
        }
    }
}