//
//  DoodadDelegate.h
//  desolate
//
//  Created by Devan Buggay on 6/28/13.
//  Copyright (c) 2013 Devan Buggay. All rights reserved.
//

#ifndef __desolate__DoodadDelegate__
#define __desolate__DoodadDelegate__

#include <deque>

#include "Doodad.h"



class DoodadDelegate
{
    sf::RenderWindow *window;
    
    std::deque<Doodad> doodad_l;
public:
    DoodadDelegate();
    
    void registerDelegate(sf::RenderWindow *win);
    
    int getSize();
    
    void update();
    void render();
};

#endif /* defined(__desolate__DoodadDelegate__) */
