//
//  game.hpp
//  Stormy
//
//  Created by MarkClifton on 5/2/16.
//  Copyright © 2016 MarkClifton. All rights reserved.
//

#pragma once

#include <map>
#include <iostream>
#include "window.hpp"
#include "gamestate.hpp"

namespace stormy { namespace states {
 
    class game {
    public:
        ~game();
        static game* getInstance();
        static void setProperties(int Width, int Height, char* Title, bool Vsync);
        
        void setState(int state);
        void loop();
        
        bool addState(int stateID, gamestate* State);
        std::unique_ptr<graphics::window> m_window;
    protected:
        std::map<int, gamestate*> m_states;
    private:
        game();
        gamestate* m_currentState;
        
        static int m_width, m_height;
        static bool m_vsync;
        static char* m_title;
    };
    
}}