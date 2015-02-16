// Copyright 2015 A.Bekkine
#ifndef PANZOOM_H_
#define PANZOOM_H_

#include "Vector.h"

class PanZoom {
 private:
    static PanZoom* _instance;
    PanZoom();
    void InitVariables();

 public:
    static PanZoom* Instance();
    ~PanZoom();

 private:
    bool _pan_mode;
    bool _zoom_mode;
    int _zoom_delta;
    Vector2i _pan_delta;
    Vector2i _pan_start;
    int _zoom_start;
    int _zoom_total;
    int _speed_factor;
};

#endif  // PANZOOM_H_
