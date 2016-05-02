//
//  Test.cpp
//  Stormy
//
//  Created by MarkClifton on 5/2/16.
//  Copyright © 2016 MarkClifton. All rights reserved.
//
#include <iostream>
#include "game.hpp"

using namespace stormy;
using namespace states;

class testState : public gamestate {
public:
    game* inst;
    
    testState(game* instance){
        inst = instance;
    }
    
    void setup(){
        
    }
    void loop(){
        inst->m_window->swap();
        inst->m_window->clear();
        glfwWaitEvents();
    }
    
    void changeState(){
        
    }
};

class Test {
public:
    Test(){
        game::game::setProperties(800, 600, (char*)"Test Window!", true);
        game::game* g = game::game::getInstance();
        
        g->addState(1, new testState(g));
        g->setState(1);
        g->loop();
    }
    
    
};

auto main() -> int {
    Test t;
    return 0;
}