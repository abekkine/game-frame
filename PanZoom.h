// Copyright 2015 A.Bekkine
#ifndef PANZOOM_H_
#define PANZOOM_H_

#include <iostream>

#include "Vector.h"
#include "Event.h"
#include "Viewport.h"

class PanZoom;

class PanZoomButtonCallback : public EventCallback {
 public:
    explicit PanZoomButtonCallback(PanZoom* instance);
    ~PanZoomButtonCallback() {}
    virtual void Call(const EventInfo& event);
 private:
    PanZoom* _pzInstance;
};

class PanZoomMotionCallback : public EventCallback {
 public:
    explicit PanZoomMotionCallback(PanZoom* instance);
    ~PanZoomMotionCallback() {}
    virtual void Call(const EventInfo& event);
 private:
    PanZoom* _pzInstance;
};

class PanZoom {
 private:
    static PanZoom* _instance;
    PanZoom();
    void InitVariables();
    void ProcessPan(const EventCallback::EventInfo& event);
    void ProcessZoom(const EventCallback::EventInfo& event);
    void PanUpdate();
    void ZoomUpdate();

 public:
    static PanZoom* Instance();
    ~PanZoom();
    void RegisterViewport(Viewport* viewport);
    void RegisterCallbacks(Event* event);
    void ButtonEvent(const EventCallback::EventInfo& event);
    void MotionEvent(const EventCallback::EventInfo& event);

 private:
    bool _pan_mode;
    bool _zoom_mode;
    int _zoom_delta;
    Vector2i _cursor;
    Vector2i _pan_delta;
    Vector2i _pan_start;
    int _zoom_start;
    int _zoom_total;
    int _speed_factor;
    Viewport* _viewport;

 public:
    PanZoomButtonCallback* buttonCallback;
    PanZoomMotionCallback* motionCallback;
};

#endif  // PANZOOM_H_
