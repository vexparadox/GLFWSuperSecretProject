//
//  GameObject.cpp
//  Project2
//
//  Created by William Meaton on 19/01/2016.
//
//

#include "GameObject.hpp"


GameObject::GameObject(const Math::Vector2D &scene, const Math::Vector2D &position, const Graphics::Rect &bounds, bool visible = true): Object(visible, bounds), position(position), scene(scene){
}

const Math::Vector2D& GameObject::getPosition(){
    return position;
}

void GameObject::setPosition(const Math::Vector2D &v){
    this->position = v;
}

void GameObject::setPosition(const float &x, const float &y){
    this->position.x = x;
    this->position.y = y;
}