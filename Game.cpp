// Copyright 2015 A.Bekkine
#include "SampleLayer.h"
#include "Game.h"

Game::Game() {}

Game::~Game() {
    Exit();
}

void Game::Init() {
    _display = new Display();
    _event = new Event();

    _display->AddLayer(new SampleLayer());

    _display->Init();
}

void Game::Exit() {
    delete _display;
}

void Game::Run() {
    while ( !_event->QuitCondition() ) {
        _display->Update();
        _event->Update();
    }
}
