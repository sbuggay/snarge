//
//  Renderer.cpp
//  Z
//
//  Created by Devan Buggay on 6/30/13.
//  Copyright (c) 2013 Devan Buggay. All rights reserved.
//

#include "Renderer.h"

Renderer::Renderer()
{
    
}

void Renderer::registerDelegate(sf::RenderWindow *win)
{
    window = win;
}

void Renderer::init()
{
    //glEnable(GL_LIGHTING);
    //glEnable(GL_NORMALIZE);
    //glEnable(GL_LIGHT0);
    
    //glShadeModel(GL_SMOOTH);
    
    // Enable Z-buffer read and write
    glEnable(GL_DEPTH_TEST);
    //glDepthMask(GL_TRUE);
    //glDepthFunc(GL_LEQUAL);
    //glDepthRange(0.0f, 1.0f);
    

    
    // Setup a perspective projection
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(90.f, window->getDefaultView().getSize().x/window->getDefaultView().getSize().y, 1.f, 500.f);
    glViewport(0, 0, window->getSize().x, window->getSize().y);
}

void Renderer::drawCube(float x, float y, float z, float size)
{
    
}