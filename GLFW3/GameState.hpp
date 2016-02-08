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
#include "TestEnemy.hpp"

class GameState : public State{
public:
    GameState();
    virtual ~GameState(){
        inputHandler = nullptr;
    }
    virtual void update();
    virtual void draw();
    std::shared_ptr<InputHandler> inputHandler;
    std::shared_ptr<WorldHandler> worldHandler;
    Player player = Player(Math::Vector2D(50, 50), Math::Vector2D(0, 0), Graphics::Rect(0, 0, 50, 250), true);
    TestEnemy t = TestEnemy(Math::Vector2D(50, 50), Math::Vector2D(1, 1), Graphics::Rect(0, 0, 50, 250), true, 50);
};
#endif /* GameState_hpp */
