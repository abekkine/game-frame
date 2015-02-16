// Copyright 2015 A.Bekkine
#ifndef PANZOOM_H_
#define PANZOOM_H_

#include <iostream>

#include "Vector.h"
#include "Event.h"

class PanZoomButtonCallback : public EventCallback {
 public:
    PanZoomButtonCallback() {}
    ~PanZoomButtonCallback() {}
    virtual void Call(const EventInfo& event) {
        std::cout << event.button << " : " << event.state << std::endl;
    }
};

class PanZoomMotionCallback : public EventCallback {
 public:
    PanZoomMotionCallback() {}
    ~PanZoomMotionCallback() {}
    virtual void Call(const EventInfo& event) {
        std::cout << event.x << ", " << event.y << std::endl;
    }
};

class PanZoom {
 private:
    static PanZoom* _instance;
    PanZoom();
    void InitVariables();

 public:
    static PanZoom* Instance();
    ~PanZoom();
    void RegisterCallbacks(Event* event);

 private:
    bool _pan_mode;
    bool _zoom_mode;
    int _zoom_delta;
    Vector2i _pan_delta;
    Vector2i _pan_start;
    int _zoom_start;
    int _zoom_total;
    int _speed_factor;

 public:
    PanZoomButtonCallback* buttonCallback;
    PanZoomMotionCallback* motionCallback;
};

#endif  // PANZOOM_H_
