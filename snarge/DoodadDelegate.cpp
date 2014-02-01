//
//  DoodadDelegate.cpp
//  desolate
//
//  Created by Devan Buggay on 6/28/13.
//  Copyright (c) 2013 Devan Buggay. All rights reserved.
//

#include "DoodadDelegate.h"

DoodadDelegate::DoodadDelegate()
{
    
}

void DoodadDelegate::registerDelegate(sf::RenderWindow *win)
{
    window = win;
}

int DoodadDelegate::getSize()
{
    return doodad_l.size();
}

void DoodadDelegate::update()
{

}

void DoodadDelegate::render()
{

}