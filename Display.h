// Copyright 2015 A.Bekkine
#ifndef DISPLAY_H_
#define DISPLAY_H_

#include <SDL/SDL.h>
#include <GL/gl.h>

class Display {
 public:
    Display();
    ~Display();
    bool Init();
    void Update();
    bool QuitCondition();
    void PollEvents();

 private:
    static void AtExit();
    void Reshape(int width, int height);

 private:
    bool _quit_condition;
    int _screen_width;
    int _screen_height;
    SDL_Surface* _screen;
    SDL_Event _event;
};

#endif  // DISPLAY_H_
