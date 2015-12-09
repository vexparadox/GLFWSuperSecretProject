//
//  Core.hpp
//  GLFW3
//
//  Created by William Meaton on 08/12/2015.
//  Copyright © 2015 WillMeaton.uk. All rights reserved.
//

#ifndef Core_hpp
#define Core_hpp

#include "BaseCore.hpp"
class Core : public BaseCore{
public:
    Core(){};
    ~Core(){};
    void draw();
    void update();
    void setup();
};

#endif /* Core_hpp */
