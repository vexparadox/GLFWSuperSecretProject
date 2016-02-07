//
//  ScenedObject.cpp
//  Project2
//
//  Created by William Meaton on 04/02/2016.
//  Copyright © 2016 WillMeaton.uk. All rights reserved.
//

#include "ScenedObject.hpp"

ScenedObject::ScenedObject(Math::Vector2D tile, Math::Vector2D scene, const Graphics::Rect &bounds, bool visible) :Object(visible, bounds), scene(scene) ,tile(tile){}