// Copyright 2015 A.Bekkine
#include <iostream>
#include <vector>
#include <map>

#include "Event.h"

Event::Event() {}

Event::~Event() {}

void Event::Update() {
    Poll();
}

void Event::InitVariables() {
    _quit_condition = false;
    _mouse.x = 0;
    _mouse.y = 0;
}

bool Event::QuitCondition() {
    return _quit_condition;
}

void Event::RegisterCallback(EventCallback::EventType type,
                             EventCallback* callback) {
    switch ( type ) {
        case EventCallback::et_BUTTON:
            _button_callbacks.push_back(callback);
            break;

        case EventCallback::et_MOTION:
            _motion_callbacks.push_back(callback);
            break;

        case EventCallback::et_KEY:
            _key_callbacks.push_back(callback);
            break;

        default:
            // default statement for other enum values.
            break;
    }
}

void Event::MotionEvent() {
    SDL_MouseMotionEvent motion = _event.motion;
    EventCallback::EventInfo eInfo;

    _mouse.x = motion.x;
    _mouse.y = motion.y;

    eInfo.event = EventCallback::et_MOTION;
    eInfo.button = EventCallback::bt_NONE;
    eInfo.state = EventCallback::st_NONE;
    eInfo.key = -1;
    eInfo.x = motion.x;
    eInfo.y = motion.y;

    // TODO(abekkine) : PanUpdate() and ZoomUpdate() reside here.
    std::vector<EventCallback *>::const_iterator i;
    for ( i = _motion_callbacks.begin(); i != _motion_callbacks.end(); ++i ) {
        (*i)->Call(eInfo);
    }
}

void Event::KeyEvent(EventCallback::StateType state) {
    SDL_KeyboardEvent key = _event.key;

    std::cout << key.keysym.sym << " : " << state << std::endl;
    if (_event.key.keysym.sym == 27) {
        _quit_condition = true;
    }
}

void Event::ButtonEvent(EventCallback::StateType state) {
    SDL_MouseButtonEvent button = _event.button;
    EventCallback::ButtonType button_type = EventCallback::bt_NONE;

    _mouse.x = button.x;
    _mouse.y = button.y;

    switch ( button.button ) {
        case SDL_BUTTON_LEFT:
            button_type = EventCallback::bt_LEFT;
            break;

        case SDL_BUTTON_RIGHT:
            button_type = EventCallback::bt_RIGHT;
            break;

        case SDL_BUTTON_MIDDLE:
            button_type = EventCallback::bt_MIDDLE;
            break;
    }

    InvokeButtonCallbacks(button_type, state);
}

void Event::InvokeButtonCallbacks(EventCallback::ButtonType button,
                                  EventCallback::StateType state) {
    EventCallback::EventInfo eInfo;

    eInfo.event = EventCallback::et_BUTTON;
    eInfo.button = button;
    eInfo.state = state;
    eInfo.key = -1;
    eInfo.x = _mouse.x;
    eInfo.y = _mouse.y;

    std::vector<EventCallback *>::const_iterator i;
    for ( i = _button_callbacks.begin(); i != _button_callbacks.end(); ++i ) {
        (*i)->Call(eInfo);
    }
}

void Event::Poll() {
    while ( SDL_PollEvent(&_event) ) {
        switch ( _event.type ) {
            case SDL_MOUSEMOTION:
                MotionEvent();
                break;

            case SDL_MOUSEBUTTONDOWN:
                ButtonEvent(EventCallback::st_DOWN);
                break;

            case SDL_MOUSEBUTTONUP:
                ButtonEvent(EventCallback::st_UP);
                break;

            case SDL_KEYDOWN:
                KeyEvent(EventCallback::st_DOWN);
                break;

            case SDL_KEYUP:
                KeyEvent(EventCallback::st_UP);
                break;

            case SDL_QUIT:
                _quit_condition = true;
                break;
        }
    }
}
