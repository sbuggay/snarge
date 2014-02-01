//
//  DecalDelegate.h
//  desolate
//
//  Created by Devan Buggay on 6/28/13.
//  Copyright (c) 2013 Devan Buggay. All rights reserved.
//

#ifndef __desolate__DecalDelegate__
#define __desolate__DecalDelegate__

#include <deque>

#include "Decal.h"

class DecalDelegate
{
    sf::RenderWindow *window;

    std::deque<Decal> decal_l;
public:
    DecalDelegate();
    
    void registerDelegate(sf::RenderWindow *win);
    
    void destroy();
    int getSize();
    
    void update();
    void render();

};

#endif /* defined(__desolate__DecalDelegate__) */
