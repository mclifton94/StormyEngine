//
//  gamestate.hpp
//  Stormy
//
//  Created by MarkClifton on 5/2/16.
//  Copyright © 2016 MarkClifton. All rights reserved.
//

#pragma once

namespace stormy { namespace states {
  
    class gamestate {
    public:
        virtual void setup() = 0;
        virtual void loop() = 0;
        virtual void changeState() = 0;
    protected:
    private:
    };
    
}}
