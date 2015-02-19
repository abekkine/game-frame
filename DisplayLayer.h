// Copyright 2015 A.Bekkine
#ifndef DISPLAYLAYER_H_
#define DISPLAYLAYER_H_

#include "Viewport.h"

class DisplayLayer {
 public:
    virtual ~DisplayLayer() {}
    virtual void Render() = 0;

 protected:
    Viewport _viewport;
};

#endif  // DISPLAYLAYER_H_
