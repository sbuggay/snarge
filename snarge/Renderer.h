//
//  Renderer.h
//  Z
//
//  Created by Devan Buggay on 6/30/13.
//  Copyright (c) 2013 Devan Buggay. All rights reserved.
//

#ifndef __Z__Renderer__
#define __Z__Renderer__

#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>

#include <iostream>

class Renderer
{
    sf::RenderWindow *window;
public:
    Renderer();
    
    void registerDelegate(sf::RenderWindow *win);
    
    void init();
    void render();
    
    //function calls for drawing cube etc
    
    void drawCube(float x, float y, float z, float size);
    
    
};

#endif /* defined(__Z__Renderer__) */
