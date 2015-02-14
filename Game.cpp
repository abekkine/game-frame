// Copyright 2015 A.Bekkine
#include "Game.h"

Game::Game() {}

Game::~Game() {
    Exit();
}

void Game::Init() {
    _display = new Display();

    _display->Init();
}

void Game::Exit() {
    delete _display;
}

void Game::Run() {
    int count = 1000;

    while ( count > 0 ) {
        _display->Update();
        count--;
    }
}
