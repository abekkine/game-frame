// Copyright 2015 A.Bekkine
#ifndef GAME_H_
#define GAME_H_

#include "Display.h"
#include "Event.h"
#include "PanZoom.h"

class Game {
 public:
    Game();
    ~Game();
    void Init();
    void Exit();
    void Run();

 private:
    Display* _display;
    Event* _event;
};

#endif  // GAME_H_
