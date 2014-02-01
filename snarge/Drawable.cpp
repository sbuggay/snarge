//
//  Drawable.cpp
//  Desolate
//
//  Created by Devan Buggay on 6/30/13.
//  Copyright (c) 2013 Devan Buggay. All rights reserved.
//


#include "Drawable.h"

Drawable::Drawable() {
    tex = new sf::Texture;
}

Drawable::~Drawable() {
    //delete tex;
}

void Drawable::draw() {
//    meant to be overloaded
}