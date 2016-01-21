//
//  SpriteHandler.cpp
//  Project2
//
//  Created by William Meaton on 20/01/2016.
//
//

#include "SpriteHandler.hpp"

SpriteHandler* SpriteHandler::instance;

SpriteHandler* SpriteHandler::getInstance(){
    if(!instance){
        instance = new SpriteHandler;
    }
    return instance;
}


void SpriteHandler::loadImages(){
    //load the images and confirm if they are or not
    for(int i = 0; i < SPRITE_CODE::END_SPRITE; i++){
        if(images[i].load(ofToDataPath("S_"+to_string(i)+".png"))){
            std::cout << "Image Loaded " << i << std::endl;
        }else{
            std::cout << "Image failed to load " << i << std::endl;
        }
    }
}

ofImage SpriteHandler::get(int i){
    if(i < SPRITE_CODE::END_SPRITE && i >= 0){
        return images[i];
    }
}