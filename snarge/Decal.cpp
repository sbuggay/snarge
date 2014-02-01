//
//  Decal.cpp
//  Desolate
//
//  Created by Devan Buggay on 6/28/13.
//  Copyright (c) 2013 Devan Buggay. All rights reserved.
//

#include "Decal.h"

Decal::Decal() {
    
}

Decal::~Decal() {
    
}

void Decal::init(int type, sf::Vector3f pos)
{
    this->pos = pos;
    tex = TextureDelegate::getTexture("grass.jpg");
    framesLeft_ = 100;
}

int Decal::update() {
    if(framesLeft_ <= 0)
        return 1;

    framesLeft_--;
    return 0;
}

void Decal::draw() {
    sf::Texture::bind(tex);
    glPushMatrix();
    glTranslatef(pos.x, pos.y, pos.z);
    glBegin(GL_QUADS);
    glColor3f(1, 1, 1);
    glTexCoord2f( 0.0, 0.0 ); glVertex3f( -5, -5, 0 );
    glTexCoord2f( 1.0, 0.0 ); glVertex3f( 5, -5, 0 );
    glTexCoord2f( 1.0, 1.0 ); glVertex3f( 5, 5, 0 );
    glTexCoord2f( 0.0, 1.0 ); glVertex3f( -5, 5, 0 );
    glEnd();
    glPopMatrix();
}