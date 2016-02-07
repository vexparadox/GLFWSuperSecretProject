//
//  Creature.hpp
//  Project2
//
//  Created by William Meaton on 19/01/2016.
//
//

#ifndef Creature_hpp
#define Creature_hpp

#include <stdio.h>
#include "GameObject.hpp"
#include "ScenedObject.hpp"

class Creature: public ScenedObject{
protected:
    float health;
    Creature(const Math::Vector2D &position, const Math::Vector2D &scene, const Graphics::Rect &bounds, bool visible, float health);
};
#endif /* Creature_hpp */
