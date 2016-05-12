//
//  RigidBody.hpp
//  closedFrameworks
//
//  Created by William Meaton on 12/05/2016.
//  Copyright © 2016 WillMeaton.uk. All rights reserved.
//

#ifndef RigidBody_hpp
#define RigidBody_hpp

#include <stdio.h>
#include "Component.hpp"

class RigidBody : public Component{
    RigidBody();
    void update();
};


#endif /* RigidBody_hpp */
