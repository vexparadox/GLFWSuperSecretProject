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
#include "Handlers.h"

class Player : public Creature{
public:
    Player(const Math::Vector2D &position, bool visible, float health);
    ~Player();
    virtual void render();
    virtual void update();
    int speed = 10;
    WorldHandler* worldHandler;
    InputHandler* inputHandler;
};

#endif /* Player_hpp */
