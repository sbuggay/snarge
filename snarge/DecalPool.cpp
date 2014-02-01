//
//  DecalPool.cpp
//  snarge
//
//  Created by Devan Buggay on 10/31/13.
//  Copyright (c) 2013 Devan Buggay. All rights reserved.
//

#include "DecalPool.h"

DecalPool::DecalPool() {
    firstAvailable_ = &decals_[0];
    
    for (int i = 0; i < POOL_SIZE - 1; i++) {
        decals_[i].setNext(&decals_[i + 1]);
    }
    
    decals_[POOL_SIZE - 1].setNext(NULL);
}

void DecalPool::create(int type, sf::Vector3f pos) {
    Decal *newDecal = firstAvailable_;
    firstAvailable_ = newDecal->getNext();
    newDecal->init(type, pos);
}

void DecalPool::update() {
    for (int i = 0; i < POOL_SIZE; i++) {
        if (decals_[i].update() > 0) {
            decals_[i].setNext(firstAvailable_);
            firstAvailable_ = &decals_[i];
        }
    }
}

void DecalPool::render() {
    for (int i = 0; i < POOL_SIZE; i++) {
        decals_[i].draw();
    }
}