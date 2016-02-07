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
    this->tile.x++;
}

void TestEnemy::render(){
    int worldX = WorldHandler::getInstance()->getOffSetX();
    int worldY = -WorldHandler::getInstance()->getOffSetY();

    if(worldX == scene.x && worldY == scene.y){
        SpriteHandler::getInstance()->get(SPRITE_CODE::player).draw(this->tile);
    }
}