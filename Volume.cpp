// Copyright 2015 A.Bekkine
#include "Volume.h"

// TODO(abekkine) : Volume not used yet.

Volume::Volume() {
    SetWidth(0.0, 0.0);
    SetHeight(0.0, 0.0);
    SetDepth(0.0, 0.0);
}

Volume::Volume(double left, double right, double bottom, double top) {
    SetWidth(left, right);
    SetHeight(bottom, top);
    SetDepth(-1.0, 1.0);
}

Volume::~Volume() {}

void Volume::SetWidth(double left, double right) {
    _left = left;
    _right = right;
}

void Volume::SetHeight(double bottom, double top) {
    _bottom = bottom;
    _top = top;
}

void Volume::SetDepth(double near, double far) {
    _near = near;
    _far = far;
}
