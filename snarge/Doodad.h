//
//  Doodad.h
//  desolate
//
//  Created by Devan Buggay on 6/28/13.
//  Copyright (c) 2013 Devan Buggay. All rights reserved.
//

#ifndef __desolate__Doodad__
#define __desolate__Doodad__

#include <iostream>

#include "Drawable.h"

enum DoodadTypes {D_CHAIR, D_TABLE};

class Doodad : public Drawable {
public:
    Doodad();
    Doodad(int type);
};

#endif /* defined(__desolate__Doodad__) */
