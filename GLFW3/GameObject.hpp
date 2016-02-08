//
//  GameObject.hpp
//  Project2
//
//  Created by William Meaton on 19/01/2016.
//
//

#ifndef GameObject_hpp
#define GameObject_hpp

#include <stdio.h>
#include "CoreMain.h"

class GameObject{
    Math::Vector2D position, scene;
    Graphics::Rect bounds;
    bool visible = false;
protected:
    GameObject(const Math::Vector2D &scene,const Math::Vector2D &position, const Graphics::Rect &bounds, bool visible = false);
public:
    const Math::Vector2D& getPosition();
    const Math::Vector2D& getScene();
    virtual void update() = 0;
    virtual void render() = 0;
    void setPosition(const Math::Vector2D &v);
    void setPosition(const float &x, const float &y);
    void setScene(const Math::Vector2D &v);
    void setScene(const float &x, const float &y);
};

#endif /* GameObject_hpp */
