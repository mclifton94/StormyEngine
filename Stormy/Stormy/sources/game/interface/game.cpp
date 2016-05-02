//
//  game.cpp
//  Stormy
//
//  Created by MarkClifton on 5/2/16.
//  Copyright © 2016 MarkClifton. All rights reserved.
//

#include "game.hpp"

namespace stormy { namespace states {
  
    int game::m_width = 0;
    int game::m_height = 0;
    bool game::m_vsync = true;
    char* game::m_title = (char*)"";
    
    //--------------------------------------------------------------------------------
    game::game(){
        m_window.reset( new graphics::window(m_width, m_height, m_title, m_vsync));
    }
    
    //--------------------------------------------------------------------------------
    game::~game(){
        for( auto& state: m_states){
            delete state.second;
        }
    }
    
    //--------------------------------------------------------------------------------
    game* game::getInstance(){
        if(m_width != 0){
            static game instance;
            return &instance;
        }
        return nullptr;
    }
    
    void game::setProperties(int Width, int Height, char* Title, bool Vsync){
        m_width = Width;
        m_height = Height;
        m_vsync = Vsync;
        m_title = Title;
    }
    
    //--------------------------------------------------------------------------------
    void game::setState(int state){
        if(m_states.count(state) > 0){
            m_currentState = m_states[state];
            m_currentState->setup();
        }else{
            std::cerr << "Invalid state!\n";
        }
    }
    
    //--------------------------------------------------------------------------------
    void game::loop(){
        while(!m_window->shouldClose()){
            m_currentState->loop();
        }
    }
    
    //--------------------------------------------------------------------------------
    bool game::addState(int stateID, gamestate* State){
        if(m_states.count(stateID) == 0){
            m_states[stateID] = State;
            return true;
        }
        return false;
    }
    
}}