//
//  WallDelegate.h
//  desolate
//
//  Created by Devan Buggay on 7/6/13.
//  Copyright (c) 2013 Devan Buggay. All rights reserved.
//

#ifndef __desolate__WallDelegate__
#define __desolate__WallDelegate__

#include <iostream>
#include <deque>

#include "Wall.h"

class WallDelegate
{
    sf::RenderWindow *window;
    
    std::deque<Wall> walls;
public:
    WallDelegate();
    
    void registerDelegate(sf::RenderWindow *win);

};

#endif /* defined(__desolate__WallDelegate__) */
