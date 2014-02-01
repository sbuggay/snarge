//
//  WallDelegate.cpp
//  desolate
//
//  Created by Devan Buggay on 7/6/13.
//  Copyright (c) 2013 Devan Buggay. All rights reserved.
//

#include "WallDelegate.h"

WallDelegate::WallDelegate() {
    
}

void WallDelegate::registerDelegate(sf::RenderWindow *win) {
    window = win;
}