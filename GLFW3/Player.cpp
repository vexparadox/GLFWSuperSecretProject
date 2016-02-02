//
//  Player.cpp
//  Project2
//
//  Created by William Meaton on 19/01/2016.
//
//

#include "Player.hpp"

Player::Player(const Math::Vector2D &position, bool visible, float health): Creature(position, visible, health){
    worldHandler = WorldHandler::getInstance();
    inputHandler = InputHandler::getInstance();
}

Player::~Player(){
    worldHandler = nullptr;
    inputHandler = nullptr;
}

void Player::update(){
    //on player movement
    if(inputHandler->getDOWN()){
        this->setPosition(this->getPosition().x, this->getPosition().y+speed);
    }
    if(inputHandler->getUP()){
        this->setPosition(this->getPosition().x, this->getPosition().y-speed);
    }
    if(inputHandler->getRIGHT()){
        this->setPosition(this->getPosition().x+speed, this->getPosition().y);
    }
    if(inputHandler->getLEFT()){
        this->setPosition(this->getPosition().x-speed, this->getPosition().y);
    }
    
    //check the positioning, move the world accordingly
    if(this->getPosition().y > worldHandler->windowHeight){
        worldHandler->offSetby(0, -1);
        this->setPosition(this->getPosition().x, 0);
    }
    
    if(this->getPosition().y < 0){
        worldHandler->offSetby(0, 1);
        this->setPosition(this->getPosition().x, worldHandler->windowHeight-SPRITE_SIZE);
    }
    
    //left and right screen detectors
    if(this->getPosition().x < 0){
        worldHandler->offSetby(-1, 0);
        this->setPosition(worldHandler->windowWidth-SPRITE_SIZE, this->getPosition().y);
    }
    
    if(this->getPosition().x > worldHandler->windowWidth){
        worldHandler->offSetby(1, 0);
        this->setPosition(0, this->getPosition().y);
    }
}

void Player::render(){
    SpriteHandler::getInstance()->get(SPRITE_CODE::player).draw(this->position);
}