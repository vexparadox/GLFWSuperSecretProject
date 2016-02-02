//
//  Utils.cpp
//  Project2
//
//  Created by William Meaton on 02/02/2016.
//  Copyright © 2016 WillMeaton.uk. All rights reserved.
//

#include "Utils.h"
namespace Math {
    void absolute(float &f){
        if(f < 0){
            f = f*-1;
        }
    }
    void absolute(int &i){
        if(i < 0){
            i = i*-1;
        }
    }
}
