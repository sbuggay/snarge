//
//  ConfigDelegate.cpp
//  desolate
//
//  Created by Devan Buggay on 6/28/13.
//  Copyright (c) 2013 Devan Buggay. All rights reserved.
//

#include "ConfigDelegate.h"

void exitWithError(const std::string &error)
{
	std::cout << error;
	std::cin.ignore();
	std::cin.get();
    
}
