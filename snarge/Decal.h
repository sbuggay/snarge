//
//  Decal.h
//  Desolate
//
//  Created by Devan Buggay on 6/28/13.
//  Copyright (c) 2013 Devan Buggay. All rights reserved.
//

#ifndef __Desolate__Decal__
#define __Desolate__Decal__

#include "Drawable.h"

enum DecalTypes {D_WATER, D_SPARK, D_BLOOD};

class Decal : public Drawable {
public:
    
    Decal *getNext() const { return next; }
    void setNext(Decal *next) { this->next = next; }
    
    Decal();
    ~Decal();
    
    void init(int type, sf::Vector3f pos);
    int update();
    void draw();
    
    
private:
    int type;
    int  framesLeft_;

    Decal *next;
};


#endif /* defined(__Desolate__Decal__) */
