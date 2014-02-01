//
//  DecalPool.h
//  snarge
//
//  Created by Devan Buggay on 10/31/13.
//  Copyright (c) 2013 Devan Buggay. All rights reserved.
//

#ifndef __snarge__DecalPool__
#define __snarge__DecalPool__

#include "Decal.h"

#include <iostream>

class DecalPool
{
public:
    DecalPool();
    
    void create(int type, sf::Vector3f pos);
    void update();
    void render();
    
private:
    static const int POOL_SIZE = 5000;
    Decal decals_[POOL_SIZE];
    Decal *firstAvailable_;
};

#endif /* defined(__snarge__DecalPool__) */
