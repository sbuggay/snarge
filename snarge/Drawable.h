//
//  Drawable.h
//  Desolate
//
//  Created by Devan Buggay on 6/30/13.
//  Copyright (c) 2013 Devan Buggay. All rights reserved.
//

#ifndef __Desolate__Drawable__
#define __Desolate__Drawable__

//sfml headers
#include <SFML/OpenGL.hpp>
#include <SFML/Graphics.hpp>

#include "TextureDelegate.h"
#include "ResourcePath.hpp"

#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

class Drawable {
public:
    
    sf::Vector3f pos;
    float angle;
    
    sf::Texture *tex;

    bool collide;
  
    Drawable();
    virtual ~Drawable();
    
    void draw();
};

#endif /* defined(__Desolate__Drawable__) */
