//
//  InputHandler.hpp
//  Project2
//
//  Created by William Meaton on 31/12/2015.
//
//

#ifndef InputHandler_hpp
#define InputHandler_hpp

#include <stdio.h>

//this class handles keyboard input with predefined buttons and static methods

class InputHandler{
    static InputHandler* instance;
    ~InputHandler();
    InputHandler(){};
    InputHandler(InputHandler const &s){}; // no copy constructor
    bool UP, LEFT, RIGHT, DOWN, isKeyPressed, SPACE, MOUSE0, MOUSE1, isMousePressed;
    int mouseX = 0, mouseY = 0;
public:
    static InputHandler* getInstance();
    void mouseInput(int x, int y);
    int getMouseX();
    int getMouseY();
    void mouseDown(int button);
    void mouseUp(int button);
    void keyUp(int key);
    void keyDown(int key);
    bool getUP();
    bool getLEFT();
    bool getRIGHT();
    bool getDOWN();
    bool getisKeyPressed();
    bool getisMousePressed();
    bool getSPACE();
    bool getMOUSE0();
    bool getMOUSE1();
    
};


#endif /* Keyboard_hpp */
