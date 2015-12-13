//
//  Vector2D.h
//  GLFW3
//
//  Created by William Meaton on 07/12/2015.
//  Copyright © 2015 WillMeaton.uk. All rights reserved.
//

#ifndef Vector2D_h
#define Vector2D_h
#include <cmath>
namespace Math {
    class Vector2D{
    public:
        float x, y;
        Vector2D(float x, float y){
            this->x = x;
            this->y = y;
        }
        Vector2D(){}
        ~Vector2D(){}
        float distance(const Vector2D v2){
            float temp = sqrt((this->x-v2.x)*(this->x-v2.x)+(this->y-v2.y)*(this->y-v2.y));
            return temp;
        }
        
        float distance(float x2, float y2){
            return(this->distance(Vector2D(x2, y2)));
        }
        
        inline friend bool operator== (const Vector2D& v1, const Vector2D& v2){
            if(v1.x == v2.x && v1.y == v2.y){
                return true;
            }
            return false;
        }
        
        inline friend bool operator!= (const Vector2D& v1, const Vector2D& v2){
            return !(v1 == v2);
        }
        
        inline friend void operator+= (Vector2D& v1, const Vector2D& v2){
            v1 = v1+v2;
            return;
        }
        
        inline Vector2D operator+ (const Vector2D& v){
            Vector2D temp;
            temp.x = this->x + v.x;
            temp.y = this->y + v.y;
            return temp;
        }
        
        inline Vector2D& operator= (const Vector2D& v){
            this->x = v.x;
            this->y = v.y;
            return *this;
        }
        
        inline Vector2D operator*(const Vector2D& v){
            Vector2D temp;
            temp.x = this->x*v.x;
            temp.y = this->y*v.y;
            return temp;
        }
        
        inline Vector2D operator*(float n){
            Vector2D temp;
            temp.x = this->x*n;
            temp.y = this->y*n;
            return temp;
        }
        
        friend inline void operator*= (Vector2D& v1, const Vector2D& v2){
            v1 = v1*v2;
            return;
        }
        
        inline Vector2D operator- (const Vector2D& v) {
            Vector2D temp;
            temp.x = this->x-v.x;
            temp.y = this->y-v.y;
            return temp;
        }
        
        inline Vector2D operator/ (const Vector2D& v) {
            Vector2D temp;
            temp.x = this->x/v.x;
            temp.y = this->y/v.y;
            return temp;
        }
        
        inline Vector2D operator/ (float n){
            Vector2D temp;
            temp.x = this->x/n;
            temp.y = this->y/n;
            return temp;
        }
        
        friend inline void operator/= (Vector2D& v1, const Vector2D& v2){
            v1 = v1/v2;
            return;
        }
        
        //normalise
        inline Vector2D normalise(){
            Vector2D* temp = this;
            float length = (float)sqrt(temp->x*temp->x + temp->y*temp->y);
                if(length > 0) {
                    temp->x/= length;
                    temp->y/= length;
                }
            return *temp;
        }

    };
}
#endif /* Vector2D_h */