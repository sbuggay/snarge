//
//  Game.cpp
//  desolate
//
//  Created by Devan Buggay on 6/28/13.
//  Copyright (c) 2013 Devan Buggay. All rights reserved.
//

#include "Game.h"

Game::Game()
{
    ConfigFile cf(resourcePath() + "config.cfg");
    string title = cf.getValueOfKey<string>("windowtitle", "no title");
    width = cf.getValueOfKey<int>("width", 600);
    height = cf.getValueOfKey<int>("height", 400);
    int aal = cf.getValueOfKey<int>("antialiaslevel", 0);
    bool fullscreen = cf.getValueOfKey<bool>("fullscreen", false);
    bool vsync = cf.getValueOfKey<bool>("verticlesync", false);
    float frameratelimit = cf.getValueOfKey("frameratelimit", 60);
    debugon = true;
    
    cout << "Width : " << width << endl << "Height : " << height << endl;
    cout << "Antialias : " << aal << endl;
    
    stringstream titles;
    titles << title << " " << version;
    ContextSettings cs;
    cs.antialiasingLevel = aal;
    cs.depthBits = 32;
    cs.stencilBits = 16;
    cs.majorVersion = 3;
    cs.minorVersion = 3;
    sf::ContextSettings context(24, 8, 2, 3, 3);
    if(fullscreen)
        window = new RenderWindow(VideoMode(width, height, 32), titles.str(), 7U, context);
    else
        window = new RenderWindow(VideoMode(width, height, 32), titles.str(), 7U, cs);
    
    window->setFramerateLimit(frameratelimit);
    window->setVerticalSyncEnabled(vsync);
    cout << "window <" << titles.str() << "> has been created" << endl;
    
    game_state = STATE_GAME;
    
    world = new World();
    
    textdelegate = new TextDelegate();
//    sounddelegate = new SoundDelegate();
    
    renderer = new Renderer();
    
    walltest = new Wall(W_CONCRETE, 50);
    walltest->addPoint(Vector2f(2200, 2200));
    walltest->addPoint(Vector2f(2200, 2500));
    walltest->addPoint(Vector2f(2500, 2500));
    walltest->addPoint(Vector2f(2500, 2200));
    walltest->addPoint(Vector2f(2200, 2200));
    
    debugplayer.pos.x = 2000;
    debugplayer.pos.y = 2000;
    debugplayer.pos.z = 5;
    
    camAngle = 0;
    camHeight = 200;
    backgroundImage.loadFromFile(resourcePath() + "checker.jpg");
}

Game::~Game() {
    
}

int Game::init()
{
    //create view
    view = new View(FloatRect(0, 0, window->getSize().x, window->getSize().y));
    window->setView(*view);
    
    rain = 20;
    
    //register delegates
    world->doodaddelegate->registerDelegate(window);
    world->itemdelgate->registerDelegate(window);

    textdelegate->registerDelegate(window);
    
    //register renderer
    renderer->registerDelegate(window);
    renderer->init();
    
    //setup text delegate
    textdelegate->setFont(resourcePath() + "sansation.ttf");
    textdelegate->setSize(16);
    
    glEnable(GL_DEPTH_TEST);
    glDepthMask(GL_TRUE);
    glDepthFunc(GL_LEQUAL);
    glDepthRange(0.0f, 1.0f);
    
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    
    //glEnable(GL_LIGHTING);
    //glEnable(GL_LIGHT0);

    
    //glLightfv(GL_LIGHT0, GL_POSITION, (GLfloat[]){2.0, 2.0, 2.0, 0.0});
    //glLightfv(GL_LIGHT0, GL_AMBIENT, (GLfloat[]){1.0, 1.0, 1.0, 0.0});
    //glEnable (GL_LIGHTING);
    //glEnable (GL_LIGHT0);
    
    
    editMode = false;
    editMenuRow = 0;
    
    return 0;
}

void Game::run() {
    while(window->isOpen()) {
        window->clear();
        game_events();
        update();
        events();
        render();
        window->display();
    }
}

void Game::events() {
    Event event;
    while (window->pollEvent(event)) {
        if (event.type == Event::Closed || Keyboard::isKeyPressed(Keyboard::Escape))
            window->close();
        else if (event.type == sf::Event::Resized) {
            glViewport(0, 0, event.size.width, event.size.height);
        }
        
        if(Keyboard::isKeyPressed(Keyboard::RShift)) {
            debugon = !debugon;
        }
        
        if(Keyboard::isKeyPressed(Keyboard::F1)) {
            editMode = !editMode;
        }
    }
}



void Game::game_events() {
    Vector2f movevector(0, 0);
    
    if (Keyboard::isKeyPressed(Keyboard::W)) movevector += Vector2f(0, 2);
    if (Keyboard::isKeyPressed(Keyboard::S)) movevector += Vector2f(0, -2);
    if (Keyboard::isKeyPressed(Keyboard::A)) movevector += Vector2f(-2, 0);
    if (Keyboard::isKeyPressed(Keyboard::D)) movevector += Vector2f(2, 0);
    if (Keyboard::isKeyPressed(Keyboard::Q)) camAngle -= 0.05;
    if (Keyboard::isKeyPressed(Keyboard::E)) camAngle += 0.05;
    if (Keyboard::isKeyPressed(Keyboard::Comma)) camHeight -= 0.5;
    if (Keyboard::isKeyPressed(Keyboard::Period)) camHeight += 0.5;
    
    if (Keyboard::isKeyPressed(Keyboard::P)) world->decalpool->create(1, debugplayer.pos);
    if (Keyboard::isKeyPressed(Keyboard::O)) rain--;
    
    if (Mouse::isButtonPressed(Mouse::Left)) {
        walltest->addPoint(sf::Vector2f(debugplayer.pos.x, debugplayer.pos.y));
    }
    
    if (Keyboard::isKeyPressed(Keyboard::Space)) {
//        sounddelegate->playSound("gunshot.wav");
    }
    
    if(movevector.x != 0 || movevector.y != 0) {
        movevector.x = (movevector.x / sqrt(pow(movevector.x, 2) + pow(movevector.y, 2)));
        movevector.y = (movevector.y / sqrt(pow(movevector.x, 2) + pow(movevector.y, 2)));
        float speed = 1;
        
        movevector.x = movevector.x * speed;
        movevector.y = movevector.y * speed;
        
        float x = movevector.x;
        float y = movevector.y;
        float cs = cos(camAngle);
        float sn = -1*sin(camAngle);
        
        movevector.x = x * cs - y * sn;
        movevector.y = x * sn + y * cs;
        
        debugplayer.pos.x += movevector.x;
        debugplayer.pos.y += movevector.y;
    }
    
    mousecoords.x = Mouse::getPosition(*window).x;
    mousecoords.y = Mouse::getPosition(*window).y;
}


void Game::update() {
    Vector2f direct;
    direct =  mousecoords - sf::Vector2f(width / 2, height / 2);
    debugplayer.angle = to_degrees(atan2(direct.y, -1 * direct.x));
    
    for(int i = 0; i < rain; i++) {
        world->particlepool->create(P_WATER, debugplayer.pos + sf::Vector3f(rand() % 300 - 150, rand() % 300 - 150, 200), sf::Vector3f(0, 0, -5), sf::Vector3f(0, 0, 0), 100);
    }
    
    world->update();
}

void Game::render()
{
    glClearColor(0.0f, 0.1f, 0.0f, 0.0f);
    glClearDepth(1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    glEnable(GL_TEXTURE_2D);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    gluLookAt(debugplayer.pos.x, debugplayer.pos.y, camHeight, debugplayer.pos.x, debugplayer.pos.y , 0, sin(camAngle),cos(camAngle),0);
    
    
    sf::Texture::bind(&backgroundImage);
    glPushMatrix();
    glTranslatef(0, 0, 0);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glBegin(GL_POLYGON);
    glColor3f(1, 1, 1);
    glTexCoord2f( 0.0, 0.0);     glVertex3f(  0,  0, 0 );
    glTexCoord2f( 8.0, 0.0);     glVertex3f(  4000,  0, 0 );
    glTexCoord2f( 8.0, 8.0);     glVertex3f(  4000,  4000, 0 );
    glTexCoord2f( 0.0, 8.0);     glVertex3f(  0,  4000, 0 );
    glEnd();
    glPopMatrix();

    sf::Texture::bind(debugplayer.tex);
    glPushMatrix();
    glTranslatef(debugplayer.pos.x, debugplayer.pos.y, 5);
    glRotatef(debugplayer.angle, 0, 0, 1);
    glBegin(GL_POLYGON);
    glColor3f(1, 1, 1);
    glTexCoord3f( 0.0, 0.0, 0.0);     glVertex3f(  10, -10, 0 );
    glTexCoord3f( 0.0, 1.0, 0.0);     glVertex3f(  10,  10, 0 );
    glTexCoord3f( 1.0, 1.0, 0.0);     glVertex3f( -10,  10, 0 );
    glTexCoord3f( 1.0, 0.0, 0.0);     glVertex3f( -10, -10, 0 );
    glEnd();
    glPopMatrix();
    
    walltest->draw();
    world->render();
    
    glFlush();
    
    window->pushGLStates();
    if(debugon) {
        stringstream buffer;
        buffer << version << endl;
        buffer << "pos : " << debugplayer.pos.x << ", " << debugplayer.pos.y << endl;;
        buffer << "camAngle : " << camAngle << endl;
        buffer << endl;
        buffer << "#rain " << rain << endl;
        buffer << "#tex-loaded " << TextureDelegate::getSize() << endl;;
        textdelegate->write(buffer.str(), Vector2i(0, 0));
    }
    
    if(editMode) {
        sf::RectangleShape menu;
        menu.setSize(Vector2f(200,height));
        menu.setPosition(width - 200, editMenuRow);
        window->draw(menu);
        
    }
    window->popGLStates();
}
