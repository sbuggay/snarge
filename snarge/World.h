//
//  World.h
//  desolate
//
//  Created by Devan Buggay on 6/29/13.
//  Copyright (c) 2013 Devan Buggay. All rights reserved.
//

#ifndef __desolate__World__
#define __desolate__World__

#include "DoodadDelegate.h"
#include "ItemDelegate.h"
#include "DecalPool.h"
#include "ParticlePool.h"
#include "WallDelegate.h"

class World {
    public:

    DecalPool *decalpool;
    DoodadDelegate *doodaddelegate;
    ItemDelegate *itemdelgate;
    ParticlePool *particlepool;
    WallDelegate *walldelegate;

    World();
    
    void update();
    void render();
    
    void save();
    void load();
};

#endif /* defined(__desolate__World__) */
