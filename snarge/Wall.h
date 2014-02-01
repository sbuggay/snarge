//
//  Wall.h
//  Z
//
//  Created by Devan Buggay on 7/1/13.
//  Copyright (c) 2013 Devan Buggay. All rights reserved.
//

#ifndef __Z__Wall__
#define __Z__Wall__

#include <iostream>
#include <deque>

#include "Drawable.h"

enum WallTypes {W_CONCRETE};

class Wall : public Drawable
{
    std::deque<sf::Vector2f> points;
    
    int type;
    float wallheight;
    
public:
    Wall();
    Wall(int type, float wallheight);
    
    void addPoint(sf::Vector2f point);
    
    void draw();
};

#endif /* defined(__Z__Wall__) */
