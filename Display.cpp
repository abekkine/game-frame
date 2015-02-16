// Copyright 2015 A.Bekkine
#include <vector>

#include "Display.h"

Display::Display() {
    _screen = 0;
    _screen_width = 800;
    _screen_height = 800;
    _quit_condition = false;
}

Display::~Display() {
    CleanupLayers();

    SDL_Quit();
}

void Display::CleanupLayers() {
    DisplayLayer* layer;
    while ( !_layers.empty() ) {
        layer = _layers.back();
        delete layer;
        _layers.pop_back();
    }
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

void Display::PreRender() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Display::PostRender() {
    SDL_GL_SwapBuffers();
}

void Display::RenderLayers() {
    std::vector< DisplayLayer* >::const_iterator iLayer;
    for (iLayer = _layers.begin(); iLayer != _layers.end(); ++iLayer) {
        (*iLayer)->Render();
    }
}

void Display::AddLayer(DisplayLayer* layer) {
    _layers.push_back(layer);
}

void Display::Update() {
    PreRender();

    RenderLayers();

    PostRender();
}
