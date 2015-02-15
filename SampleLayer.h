// Copyright 2015 A.Bekkine
#ifndef SAMPLELAYER_H_
#define SAMPLELAYER_H_

#include "DisplayLayer.h"

class SampleLayer : public DisplayLayer {
 public:
    SampleLayer();
    ~SampleLayer();
    virtual void Render();
};

#endif  // SAMPLELAYER_H_
