//
//  TextDelegate.cpp
//  desolate
//
//  Created by Devan Buggay on 6/29/13.
//  Copyright (c) 2013 Devan Buggay. All rights reserved.
//

#include "TextDelegate.h"

TextDelegate::TextDelegate() {
    
}

void TextDelegate::registerDelegate(sf::RenderWindow *win) {
    window = win;
}

void TextDelegate::setFont(std::string fontFile) {
    if (!font.loadFromFile(fontFile))
        std::cout << "Could not load font" << std::endl;
    else
        textBuffer.setFont(font);
}

void TextDelegate::setSize(int size) {
    textBuffer.setCharacterSize(size);
}

void TextDelegate::write(std::string text, sf::Vector2i pos) {
    textBuffer.setString(text);
    textBuffer.setPosition(window->mapPixelToCoords(pos));
    
    window->draw(textBuffer);
}