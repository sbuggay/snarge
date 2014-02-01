//
//  ParticlePool.h
//  snarge
//
//  Created by Devan Buggay on 10/29/13.
//  Copyright (c) 2013 Devan Buggay. All rights reserved.
//

#ifndef __snarge__ParticlePool__
#define __snarge__ParticlePool__

#include "Particle.h"

#include <iostream>

class ParticlePool
{
public:
    ParticlePool();
    
    void create(int type, sf::Vector3f pos, sf::Vector3f vel, sf::Vector3f acc, int lifetime);
    void update();
    void render();
    
private:
    static const int POOL_SIZE = 5000;
    Particle particles_[POOL_SIZE];
    Particle *firstAvailable_;
};


#endif /* defined(__snarge__ParticlePool__) */
