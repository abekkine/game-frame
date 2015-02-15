// Copyright 2015 A.Bekkine
#ifndef DISPLAY_H_
#define DISPLAY_H_

#include <SDL/SDL.h>
#include <GL/gl.h>

#include <vector>

#include "DisplayLayer.h"

class Display {
 public:
    Display();
    ~Display();
    bool Init();
    void Update();
    bool QuitCondition();
    void PollEvents();
    void AddLayer(DisplayLayer* layer);

 private:
    static void AtExit();
    void Reshape(int width, int height);
    void PreRender();
    void PostRender();
    void RenderLayers();
    void CleanupLayers();

 private:
    bool _quit_condition;
    int _screen_width;
    int _screen_height;
    SDL_Surface* _screen;
    SDL_Event _event;
    std::vector< DisplayLayer* > _layers;
};

#endif  // DISPLAY_H_
