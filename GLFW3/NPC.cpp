//
//  NPC.cpp
//  Project2
//
//  Created by William Meaton on 19/01/2016.
//
//

#include "NPC.hpp"


NPC::NPC(const Math::Vector2D &position, const Math::Vector2D &scene, const Graphics::Rect &bounds, bool visible, float health) : Creature(position, scene, bounds,visible, health){
}