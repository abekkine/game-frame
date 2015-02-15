// Copyright 2015 A.Bekkine
#include "SampleLayer.h"
#include "Game.h"

Game::Game() {}

Game::~Game() {
    Exit();
}

void Game::Init() {
    _display = new Display();

    _display->AddLayer(new SampleLayer());

    _display->Init();
}

void Game::Exit() {
    delete _display;
}

void Game::Run() {
    while ( !_display->QuitCondition() ) {
        _display->Update();
        _display->PollEvents();
    }
}
