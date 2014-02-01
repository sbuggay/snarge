//
//  Particle.cpp
//  Desolate
//
//  Created by Devan Buggay on 6/28/13.
//  Copyright (c) 2013 Devan Buggay. All rights reserved.
//

#include "Particle.h"

Particle::Particle() {
    
}

Particle::~Particle() {

}

Particle::Particle(int type) {
    this->type = type;
    switch (type)
    {
        case P_WATER:
            tex = TextureDelegate::getTexture("water.png");
            vel.z = -4;
            acc.z = -.2;
            framesLeft_ = 100;
        default:
            
            break;
    }
}

void Particle::init(int type, sf::Vector3f pos, sf::Vector3f vel, sf::Vector3f acc, int lifetime)
{
    this->pos = pos;
    this->vel = vel;
    this->acc = acc;
    tex = TextureDelegate::getTexture("water.png");
    framesLeft_ = lifetime;
}

int Particle::update() {
    if(framesLeft_ <= 0)
        return 1;
    if(pos.z < 0)
        return 2;
    
    vel += acc;
    pos += vel;
    framesLeft_--;
    return 0;
}

void Particle::draw() {
    sf::Texture::bind(tex);
    glPushMatrix();
    glTranslatef(pos.x, pos.y, pos.z);
    glBegin(GL_QUADS);
    glColor3f(1, 1, 1);
    glTexCoord2f( 0.0, 0.0 ); glVertex3f( -.5, -.5, 0 );
    glTexCoord2f( 1.0, 0.0 ); glVertex3f( .5, -.5, 0 );
    glTexCoord2f( 1.0, 1.0 ); glVertex3f( .5, .5, 0 );
    glTexCoord2f( 0.0, 1.0 ); glVertex3f( -.5, .5, 0 );
    glEnd();
    glPopMatrix();
}