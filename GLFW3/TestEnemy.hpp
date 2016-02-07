//
//  TestEnemy.hpp
//  Project2
//
//  Created by William Meaton on 07/02/2016.
//  Copyright © 2016 WillMeaton.uk. All rights reserved.
//

#ifndef TestEnemy_hpp
#define TestEnemy_hpp

#include <stdio.h>
#include "NPC.hpp"


class TestEnemy : public NPC{
public:
    TestEnemy(const Math::Vector2D &position, const Math::Vector2D &scene, const Graphics::Rect &bounds, bool visible, float health);
    void render();
    void update();
};

#endif /* TestEnemy_hpp */
