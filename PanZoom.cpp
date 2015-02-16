// Copyright 2015 A.Bekkine
#include "PanZoom.h"

// TODO(abekkine) : PanZoom not used yet.

PanZoom* PanZoom::_instance = 0;

PanZoom* PanZoom::Instance() {
    if ( _instance == 0 ) {
        _instance = new PanZoom();
    }

    return _instance;
}

PanZoom::PanZoom() {
    InitVariables();
}

PanZoom::~PanZoom() {
    delete buttonCallback;
    delete motionCallback;
}

void PanZoom::InitVariables() {
    _pan_mode = false;
    _zoom_mode = false;
    _zoom_delta = 0;
    _pan_delta.x = 0;
    _pan_delta.y = 0;
    _pan_start.x = 0;
    _pan_start.y = 0;
    _zoom_start = 0;
    _zoom_total = 0;
    _speed_factor = 1;

    buttonCallback = new PanZoomButtonCallback();
    motionCallback = new PanZoomMotionCallback();
}

void PanZoom::RegisterCallbacks(Event* event) {
    event->RegisterCallback(EventCallback::et_BUTTON, buttonCallback);
    event->RegisterCallback(EventCallback::et_MOTION, motionCallback);
}

