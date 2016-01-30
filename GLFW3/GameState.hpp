//
//  GameState.hpp
//  Project2
//
//  Created by William Meaton on 21/01/2016.
//  Copyright © 2016 WillMeaton.uk. All rights reserved.
//

#ifndef GameState_hpp
#define GameState_hpp

#include <stdio.h>
#include "State.hpp"
#include <vector>
#include "Handlers.h"
#include "Player.hpp"

class GameState : public State{
public:
    GameState();
    virtual ~GameState();
    void update();
    void draw();
    InputHandler* inputHandler;
    WorldHandler* worldHandler;
    std::vector<GameObject*> objects;
    Player a = Player(Math::Vector2D(20, 20), true, 50);
};
#endif /* GameState_hpp */
