//
//  TextureDelegate.h
//  desolate
//
//  Created by Devan Buggay on 6/28/13.
//  Copyright (c) 2013 Devan Buggay. All rights reserved.
//

#ifndef __desolate__TextureDelegate__
#define __desolate__TextureDelegate__

#include <SFML/Graphics.hpp>
#include <string>
#include <map>

#include "ResourcePath.hpp"

using namespace std;

class TextureDelegate
{
    static map<string, sf::Texture*> textures;
    TextureDelegate();
public:
    ~TextureDelegate();
    
    static sf::Texture *getTexture(string str);
    static unsigned int getSize();
};

#endif /* defined(__desolate__TextureDelegate__) */
