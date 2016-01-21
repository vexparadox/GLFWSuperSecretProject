//
//  NPC.hpp
//  Project2
//
//  Created by William Meaton on 19/01/2016.
//
//

#ifndef NPC_hpp
#define NPC_hpp

#include <stdio.h>
#include "Creature.hpp"

class NPC : public Creature{
protected:
    NPC(Math::Vector2D position, bool visible, float health);
};

#endif /* NPC_hpp */
