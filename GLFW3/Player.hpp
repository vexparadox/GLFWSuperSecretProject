//
//  Player.hpp
//  Project2
//
//  Created by William Meaton on 19/01/2016.
//
//

#ifndef Player_hpp
#define Player_hpp

#include <stdio.h>
#include "Creature.hpp"

class Player : public Creature{
public:
    Player(ofPoint position, bool visible, float health);
};

#endif /* Player_hpp */
