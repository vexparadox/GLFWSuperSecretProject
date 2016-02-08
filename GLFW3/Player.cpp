//
//  Player.cpp
//  Project2
//
//  Created by William Meaton on 19/01/2016.
//
//

#include "Player.hpp"

Player::Player(const Math::Vector2D &scene, const Math::Vector2D &position, const Graphics::Rect &bounds, bool visible): GameObject(scene, position, bounds, visible){
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
        Math::Vector2D sv(0, speed);
        worldHandler->movementCheck(editPosition(), sv, true);
    }
    if(inputHandler->getUP()){
        Math::Vector2D sv(0, -speed);
        worldHandler->movementCheck(editPosition(), sv, true);
        this->setPosition(this->getPosition().x, this->getPosition().y-speed);
    }
    if(inputHandler->getRIGHT()){
        Math::Vector2D sv(speed, 0);
        worldHandler->movementCheck(editPosition(), sv, true);
    }
    if(inputHandler->getLEFT()){
        Math::Vector2D sv(-speed, 0);
        worldHandler->movementCheck(editPosition(), sv, true);
    }

}

void Player::render(){
    SpriteHandler::getInstance()->get(SPRITE_CODE::player)->draw(this->getPosition());
}