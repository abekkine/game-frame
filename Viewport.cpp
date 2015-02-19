// Copyright 2015 A.Bekkine
#include <iostream>

#include "Viewport.h"

// TODO(abekkine) : Viewport not used yet.

Viewport::Viewport() {
    SetWidth(-1.0, 1.0);
    SetHeight(-1.0, 1.0);
    SetDepth(-1.0, 1.0);
    InitVariables();
}

Viewport::Viewport(double l, double r, double b, double t) {
    SetWidth(l, r);
    SetHeight(b, t);
    SetDepth(-1.0, 1.0);
    InitVariables();
}

Viewport::~Viewport() {}

void Viewport::InitVariables() {
    _zoom_level = 1.0;
    _center_x = 0.0;
    _center_y = 0.0;
    // TODO(abekkine) : World and screen dimensions should be read from same place.
    _world_width = 2.0;
    _world_height = 2.0;
    _screen_width = 800;
    _screen_height = 800;

    _scale_x = (right - left) / _screen_width;
    _scale_y = (bottom - top) / _screen_height;

}

void Viewport::SetWidth(double l, double r) {
    left = l;
    right = r;
}

void Viewport::SetHeight(double b, double t) {
    bottom = b;
    top = t;
}

void Viewport::SetDepth(double n, double f) {
    near = n;
    far = f;
}

void Viewport::Update(double delta_x, double delta_y, double delta_zoom) {
    double z_width, z_height;

    // TODO(abekkine) : Zooming and Panning factors should be configurable per layer.
    _zoom_level += delta_zoom * 0.002;
    _center_x -= _scale_x * delta_x;
    _center_y -= _scale_y * delta_y;
    z_width = 0.5 * _world_width * _zoom_level;
    z_height = 0.5 * _world_height * _zoom_level;

    _scale_x = (right - left) / _screen_width;
    _scale_y = (bottom - top) / _screen_height;

    left = _center_x - z_width;
    right = _center_x + z_width;
    top = _center_y + z_height;
    bottom = _center_y - z_height;
}

