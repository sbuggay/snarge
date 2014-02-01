//
//  TextureDelegate.cpp
//  desolate
//
//  Created by Devan Buggay on 6/28/13.
//  Copyright (c) 2013 Devan Buggay. All rights reserved.
//

#include "TextureDelegate.h"

TextureDelegate::TextureDelegate() {
}

map<string, sf::Texture*> TextureDelegate::textures;

sf::Texture *TextureDelegate::getTexture(string str) {
    str = resourcePath() + str;
    if(textures.find(str) != textures.end())
        return textures[str];
    
    sf::Texture *texture = new sf::Texture();
    if(texture->loadFromFile(str)) {
        textures[str] = texture;
        return textures[str];
    }
    else {
        delete texture;
        return NULL;
    }
    
}

unsigned int TextureDelegate::getSize() {
    return textures.size();
}

TextureDelegate::~TextureDelegate() {
    sf::Texture *texture;
    map<string, sf::Texture*>::iterator iter = textures.begin();
    while(iter != textures.end()) {
        texture = iter->second;
        delete texture;
        iter++;
    }
    textures.clear();
}