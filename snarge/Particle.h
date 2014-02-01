//
//  Particle.h
//  Desolate
//
//  Created by Devan Buggay on 6/28/13.
//  Copyright (c) 2013 Devan Buggay. All rights reserved.
//

#ifndef __Desolate__Particle__
#define __Desolate__Particle__

#include "Drawable.h"

enum ParticleTypes {P_WATER, P_SPARK, P_BLOOD};

class Particle : public Drawable {
public:
    
    Particle *getNext() const { return state_.next; }
    void setNext(Particle *next) { state_.next = next; }
    
    Particle();
    ~Particle();
    Particle(int type);
    
    void init(int type, sf::Vector3f pos, sf::Vector3f vel, sf::Vector3f acc, int lifetime);
    int update();
    void draw();
    
    
private:
    int type;
    int  framesLeft_;
    sf::Vector3f vel;
    sf::Vector3f acc;
    
    union {
        struct {
            int  x, y;
            int  xVel, yVel;
        } live;
        Particle *next;
    } state_;
};



#endif /* defined(__Desolate__Particle__) */
