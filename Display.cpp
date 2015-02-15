// Copyright 2015 A.Bekkine
#include "Display.h"

Display::Display() {
    _screen = 0;
    _screen_width = 800;
    _screen_height = 800;
    _quit_condition = false;
}

Display::~Display() {
    SDL_Quit();
}

bool Display::QuitCondition() {
    return _quit_condition;
}

bool Display::Init() {
    int result;

    result = SDL_Init(SDL_INIT_VIDEO);
    if ( result < 0 ) {
        fprintf(stderr, "Unable to init SDL : %s\n", SDL_GetError() );
        return false;
    }

    atexit(Display::AtExit);

    _screen = SDL_SetVideoMode(_screen_width, _screen_height, 32, SDL_OPENGL);
    if ( _screen == NULL ) {
        fprintf(stderr, "Unable to set video mode : %s\n", SDL_GetError() );
        return false;
    }

    glShadeModel(GL_SMOOTH);
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClearDepth(1.0f);
    glHint(GL_LINE_SMOOTH_HINT, GL_NICEST);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    Reshape(_screen_width, _screen_height);

    return true;
}

void Display::AtExit() {
    SDL_Quit();
}

void Display::Reshape(int width, int height) {
    if ( height == 0 ) {
        height = 1;
    }

    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1.0f, 1.0f, 1.0f, -1.0f, -1.0f, 1.0f);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void Display::PollEvents() {

    while( SDL_PollEvent(&_event) ) {
        switch( _event.type ) {
            case SDL_QUIT:
                _quit_condition = true;
                break;
            case SDL_KEYDOWN:
                if(_event.key.keysym.sym == 27) {
                    _quit_condition = true;
                }
                break;


        }
    }
}

void Display::Update() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    // Render a simple shape.
    glColor3d(1.0, 1.0, 1.0);
    glBegin(GL_TRIANGLES);
        glVertex2d(0.0, 0.75);
        glVertex2d(0.65, -0.375);
        glVertex2d(-0.65, -0.375);
    glEnd();

    SDL_GL_SwapBuffers();
}
