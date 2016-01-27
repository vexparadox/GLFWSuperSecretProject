//
//  Player.cpp
//  Project2
//
//  Created by William Meaton on 19/01/2016.
//
//

#include "Player.hpp"

Player::Player(const Math::Vector2D &position, bool visible, float health): Creature(position, visible, health){
    
}

void Player::render(){
    SpriteHandler::getInstance()->get(SPRITE_CODE::player).draw(this->position);
}