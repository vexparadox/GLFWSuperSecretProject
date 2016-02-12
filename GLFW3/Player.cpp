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

void Player::update(){
    Math::Vector2D sv(0, 0);
    //on player movement
    if(inputHandler->getDOWN()){
        sv.y += speed;
    }
    if(inputHandler->getUP()){
        sv.y += -speed;
    }
    if(inputHandler->getRIGHT()){
        sv.x += speed;
    }
    if(inputHandler->getLEFT()){
        sv.x += -speed;
    }
    worldHandler->movementCheck(editPosition(), sv, editScene(), true, true);
}

void Player::render(){
    SpriteHandler::getInstance()->get(SPRITE_CODE::player)->draw(this->getPosition());
}