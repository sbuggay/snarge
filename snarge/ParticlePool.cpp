//
//  ParticlePool.cpp
//  snarge
//
//  Created by Devan Buggay on 10/29/13.
//  Copyright (c) 2013 Devan Buggay. All rights reserved.
//

#include "ParticlePool.h"

ParticlePool::ParticlePool() {
    firstAvailable_ = &particles_[0];
    
    for (int i = 0; i < POOL_SIZE - 1; i++) {
        particles_[i].setNext(&particles_[i + 1]);
    }
    
    particles_[POOL_SIZE - 1].setNext(NULL);
}

void ParticlePool::create(int type, sf::Vector3f pos, sf::Vector3f vel, sf::Vector3f acc, int lifetime) {
    Particle *newParticle = firstAvailable_;
    firstAvailable_ = newParticle->getNext();
    newParticle->init(type, pos, vel, acc, lifetime);
}

void ParticlePool::update() {
    for (int i = 0; i < POOL_SIZE; i++) {
        if (particles_[i].update() > 0) {
            particles_[i].setNext(firstAvailable_);
            firstAvailable_ = &particles_[i];
        }
    }
}

void ParticlePool::render() {
    for (int i = 0; i < POOL_SIZE; i++) {
        particles_[i].draw();
    }
}