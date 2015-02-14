// Copyright 2015 A.Bekkine
#include <iostream>

#include "Game.h"

int main() {
    Game *game = new Game();

    game->Init();

    game->Run();

    delete game;

    return 0;
}


