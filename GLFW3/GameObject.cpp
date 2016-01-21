//
//  GameObject.cpp
//  Project2
//
//  Created by William Meaton on 19/01/2016.
//
//

#include "GameObject.hpp"


GameObject::GameObject(Math::Vector2D position, bool visible = true): visible(visible), position(position){
}

GameObject::GameObject(float x, float y, bool visible = true): visible(visible){
    position.x = x;
    position.y = y;
}

void GameObject::render(){
}