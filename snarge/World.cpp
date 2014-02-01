//
//  World.cpp
//  desolate
//
//  Created by Devan Buggay on 6/29/13.
//  Copyright (c) 2013 Devan Buggay. All rights reserved.
//

#include "World.h"

World::World() {
    decalpool = new DecalPool();
    doodaddelegate = new DoodadDelegate();
    itemdelgate = new ItemDelegate();
    particlepool = new ParticlePool();
    walldelegate = new WallDelegate();
}

void World::update() {
    decalpool->update();
    doodaddelegate->update();
    itemdelgate->update();
    particlepool->update();
}

void World::render() {
    decalpool->render();
    doodaddelegate->render();
    itemdelgate->render();
    particlepool->render();
}

void World::save() {
    
}

void World::load() {
    
}