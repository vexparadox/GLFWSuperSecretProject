//
//  TestEnemy.cpp
//  Project2
//
//  Created by William Meaton on 07/02/2016.
//  Copyright © 2016 WillMeaton.uk. All rights reserved.
//

#include "TestEnemy.hpp"

TestEnemy::TestEnemy(const Math::Vector2D &position, const Math::Vector2D &scene, const Graphics::Rect &bounds, bool visible, float health) : NPC(position, scene, bounds, visible, health){
    
}

void TestEnemy::update(){
    Math::Vector2D sv(1, 0);
    WorldHandler::getInstance()->movementCheck(editPosition(), sv, editScene(), true, false);
}

void TestEnemy::render(){
    SpriteHandler::getInstance()->get(SPRITE_CODE::player)->draw(this->getPosition());
}