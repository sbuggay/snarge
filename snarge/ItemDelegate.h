//
//  ItemDelegate.h
//  Z
//
//  Created by Devan Buggay on 6/28/13.
//  Copyright (c) 2013 Devan Buggay. All rights reserved.
//

#ifndef __Z__ItemDelegate__
#define __Z__ItemDelegate__

#include <iostream>
#include <list>

#include "Item.h"

class ItemDelegate
{
    
    sf::RenderWindow *window;
    
    std::list<Item> item_l;
public:
    ItemDelegate();
    ~ItemDelegate();
    
    void registerDelegate(sf::RenderWindow *win);
    
    void create();
    void destroy();
    
    int getSize();
    
    void update();
    void render();
};

#endif /* defined(__Z__ItemDelegate__) */
