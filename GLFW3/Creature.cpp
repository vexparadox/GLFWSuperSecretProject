//
//  Creature.cpp
//  Project2
//
//  Created by William Meaton on 19/01/2016.
//
//

#include "Creature.hpp"

Creature::Creature(const Math::Vector2D &position, const Math::Vector2D &scene, const Graphics::Rect &bounds, bool visible = true, float health = 0): GameObject(scene, position, bounds, visible), health(health){
}