// Copyright 2015 A.Bekkine
#include "PanZoom.h"

// TODO(abekkine) : PanZoom not used yet.

// Callback Definitions
PanZoomButtonCallback::PanZoomButtonCallback(PanZoom* instance) {
    _pzInstance = instance;
}

void PanZoomButtonCallback::Call(const EventInfo& event) {
    _pzInstance->ButtonEvent(event);
}

PanZoomMotionCallback::PanZoomMotionCallback(PanZoom* instance) {
    _pzInstance = instance;
}

void PanZoomMotionCallback::Call(const EventInfo& event) {
    _pzInstance->MotionEvent(event);
}
// End

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
    _cursor.x = 0;
    _cursor.y = 0;
    _zoom_start = 0;
    _zoom_total = 0;
    _speed_factor = 1;

    buttonCallback = new PanZoomButtonCallback(this);
    motionCallback = new PanZoomMotionCallback(this);
}

void PanZoom::RegisterCallbacks(Event* event) {
    event->RegisterCallback(EventCallback::et_BUTTON, buttonCallback);
    event->RegisterCallback(EventCallback::et_MOTION, motionCallback);
}

void PanZoom::ButtonEvent(const EventCallback::EventInfo& event) {
    switch ( event.button ) {
        case EventCallback::bt_RIGHT:
            ProcessPan(event);
            break;

        case EventCallback::bt_MIDDLE:
            ProcessZoom(event);
            break;

        default:
            // Put for unhandled enum values.
            break;
    }
}

void PanZoom::MotionEvent(const EventCallback::EventInfo& event) {
    _cursor.x = event.x;
    _cursor.y = event.y;

    PanUpdate();
    ZoomUpdate();
}

void PanZoom::ProcessPan(const EventCallback::EventInfo& event) {
    if ( event.state == EventCallback::st_DOWN ) {
        _pan_mode = true;
        _pan_start.x = event.x;
        _pan_start.y = event.y;

    } else if ( event.state == EventCallback::st_UP ) {
        _pan_mode = false;
    }
}

void PanZoom::ProcessZoom(const EventCallback::EventInfo& event) {
    if ( event.state == EventCallback::st_DOWN ) {
        _zoom_mode = true;
        _zoom_start = event.y;
    } else if ( event.state == EventCallback::st_UP ) {
        _zoom_mode = false;
    }
}

void PanZoom::PanUpdate() {
    if ( _pan_mode ) {
        _pan_delta.x = (_cursor.x - _pan_start.x) * _speed_factor;
        _pan_delta.y = (_cursor.y - _pan_start.y) * _speed_factor;

        // TODO(abekkine) : Pan Command to Viewport.
        std::cout << "pan delta ( ";
        std::cout << _pan_delta.x << ", ";
        std::cout << _pan_delta.y << " )" << std::endl;

        _pan_start.x = _cursor.x;
        _pan_start.y = _cursor.y;
    }
}

void PanZoom::ZoomUpdate() {
    if ( _zoom_mode ) {
        _zoom_delta = (_cursor.y - _zoom_start) * _speed_factor;

        // TODO(abekkine) : Zoom Command to Viewport.
        std::cout << "zoom delta ( " << _zoom_delta << " )" << std::endl;

        _zoom_start = _cursor.y;
    }
}

