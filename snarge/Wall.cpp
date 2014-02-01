//
//  Wall.cpp
//  Z
//
//  Created by Devan Buggay on 7/1/13.
//  Copyright (c) 2013 Devan Buggay. All rights reserved.
//

#include "Wall.h"

Wall::Wall() {
}

Wall::Wall(int type, float wallheight) {
    this->type = type;
    this->wallheight = wallheight;
    switch (type) {
        case W_CONCRETE:
            tex = TextureDelegate::getTexture("concrete.png");
            break;
        default:
            
            break;
    }
}


void Wall::addPoint(sf::Vector2f point)
{
    points.push_back(point);
}

void Wall::draw()
{
    sf::Texture::bind(tex);
    glPushMatrix();
    glBegin(GL_QUADS);
    sf::Vector2f prev;
    bool first = true;
    bool alt = false;
    for (sf::Vector2f &point: points)
    {
        if(!first)
        {if(alt) {
            glTexCoord2f( 0.0, 0.0); glVertex3f(  prev.x,  prev.y, 0 );
            glTexCoord2f( 0.0, 1.0); glVertex3f(  prev.x,  prev.y, wallheight );
        }
        else {
            glTexCoord2f( 1.0, 1.0); glVertex3f(  prev.x,  prev.y, 0 );
            glTexCoord2f( 1.0, 0.0); glVertex3f(  prev.x,  prev.y, wallheight );
        }
            alt = !alt;
        }
        else
        {
            glTexCoord2f( 1.0, 1.0); glVertex3f(  point.x,  point.y, wallheight );
            glTexCoord2f( 1.0, 0.0); glVertex3f(  point.x,  point.y, 0 );
        }
        if(alt) {
            glTexCoord2f( 0.0, 1.0); glVertex3f(  point.x,  point.y, wallheight );
            glTexCoord2f( 0.0, 0.0); glVertex3f(  point.x,  point.y, 0 );
        }
        else {
            glTexCoord3f( 1.0, 0.0, 0.0); glVertex3f(  point.x,  point.y, wallheight );
            glTexCoord3f( 1.0, 1.0, 0.0); glVertex3f(  point.x,  point.y, 0 );
        }
        alt = !alt;
        prev.x = point.x;
        prev.y = point.y;
        first = false;
    }
    glEnd();
    glPopMatrix();
    sf::Texture::bind(NULL);
    glPushMatrix();
    glBegin(GL_QUADS);
    first = true;
    for (sf::Vector2f &point: points)
    {
        glColor3f(0, 0, 0);

        if(!first)
        {
            glVertex3f(  prev.x,  prev.y, wallheight );
            glVertex3f(  prev.x,  prev.y, 300 );
        }
        else
        {
            glVertex3f(  point.x,  point.y, 300 );
            glVertex3f(  point.x,  point.y, wallheight );
        }
        glVertex3f(  point.x,  point.y, 300 );
        glVertex3f(  point.x,  point.y, wallheight );
        prev.x = point.x;
        prev.y = point.y;
        first = false;
    }
    glEnd();
    glPopMatrix();
    
    //if(losblock)
    //draw shadow on top
}