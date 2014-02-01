//
//  Game.h
//  desolate
//
//  Created by Devan Buggay on 6/28/13.
//  Copyright (c) 2013 Devan Buggay. All rights reserved.
//

#ifndef __desolate__Game__
#define __desolate__Game__

#define version "0.1.1a"
//x.0.0 - release version (0 or 1)
//0.x.0 - major change
//0.0.x - minor change

//SFML HEADERS
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

//OPENGL HEADERS
#include <SFML/OpenGL.hpp>

//C++ HEADERS
#include <vector>
#include <iostream>
#include <sstream>
#include <cmath>

//DELEGATE HEADERS
#include "TextDelegate.h"
#include "TextureDelegate.h"
//#include "SoundDelegate.h"
#include "ConfigDelegate.h"

//GAME HEADERS
#include "World.h"
#include "Renderer.h"
#include "Player.h"
#include "devmath.h"

#ifdef _WIN64
#include "ResourcePath.h"
#elif _WIN32
#include "ResourcePath.h"
#elif __APPLE__
#include <OpenAL/al.h>
#include <OpenAl/alc.h>
#include "ResourcePath.hpp"

#elif __linux

#elif __unix

#elif __posix

#endif



enum game_states{S_SPLASH, STATE_MENU, STATE_GAME, STATE_GAMEMENU};

using namespace std;
using namespace sf;

class Game
{
private:
	RenderWindow *window;
	View *view;
    
    int width;
    int height;

    World *world;
    
    TextDelegate *textdelegate;
    
    Renderer *renderer;
    
    Player debugplayer;
    sf::Texture tex;
    
	Vector2f mousecoords;
    
    sf::Texture backgroundImage;
    
    float angle;
    float camAngle;
    float camHeight;

    Wall *walltest;
    
    int rain;
public:
	Game();
    ~Game();
    
    int init();
	void run();
	void update();
	void events();
	void game_events();
	void render();

    bool showInv;
	bool debugon;
	bool showdebug;
    
    bool editMode;
    
    float editMenuRow;
    
	int game_state;
};


#endif /* defined(__desolate__Game__) */
