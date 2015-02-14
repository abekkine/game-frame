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

 private:
    static void AtExit();
    void Reshape(int width, int height);

 private:
    int _screen_width;
    int _screen_height;
    SDL_Surface* _screen;
};

#endif  // DISPLAY_H_
