//
//  TextDelegate.h
//  desolate
//
//  Created by Devan Buggay on 6/29/13.
//  Copyright (c) 2013 Devan Buggay. All rights reserved.
//

#ifndef __desolate__TextDelegate__
#define __desolate__TextDelegate__

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include <iostream>
#include <string>

class TextDelegate {
    sf::Font font;
    sf::Text textBuffer;
    
    sf::RenderWindow *window;
public:
    TextDelegate();
    
    void registerDelegate(sf::RenderWindow *win);
    
    void setFont(std::string);
    void setSize(int size);
    
    void write(std::string, sf::Vector2i);
};

#endif /* defined(__desolate__TextDelegate__) */
