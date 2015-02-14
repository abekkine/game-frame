// Copyright 2015 A.Bekkine
#ifndef GAME_H_
#define GAME_H_

#include "Display.h"

class Game {
 public:
    Game();
    ~Game();
    void Init();
    void Exit();
    void Run();

 private:
    Display* _display;
};

#endif  // GAME_H_
