//
//  DecalDelegate.cpp
//  desolate
//
//  Created by Devan Buggay on 6/28/13.
//  Copyright (c) 2013 Devan Buggay. All rights reserved.
//

#include "DecalDelegate.h"

DecalDelegate::DecalDelegate() {
    
}

void DecalDelegate::registerDelegate(sf::RenderWindow * win) {
    window = win;
}


int DecalDelegate::getSize() {
    return decal_l.size();
}

void DecalDelegate::update() {
    auto i = std::begin(decal_l);
    while (i != std::end(decal_l)) {
        if (i->update())
            i = decal_l.erase(i);
        else
            ++i;
    }

}
void DecalDelegate::render() {
    for (Decal &decal: decal_l) {
        
        glPushMatrix();
        glTranslatef(decal.pos.x, decal.pos.y, 0.f);

        float size = 2.f;
        glBegin(GL_QUADS);
        
        glColor3f(1, 1, 0);
        glTexCoord2f(0, 0); glVertex3f(-size, -size, 0.0f);
        glTexCoord2f(0, 1); glVertex3f(-size,  size, 0.0f);
        glTexCoord2f(1, 1); glVertex3f( size,  size, 0.0f);
        glTexCoord2f(1, 0); glVertex3f( size, -size, 0.0f);
        
        glEnd();
        glPopMatrix();
    }
}