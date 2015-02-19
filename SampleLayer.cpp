// Copyright 2015 A.Bekkine
#include <GL/gl.h>

#include "PanZoom.h"
#include "SampleLayer.h"

SampleLayer::SampleLayer() {
    PanZoom::Instance()->RegisterViewport(&_viewport);
}

SampleLayer::~SampleLayer() {}

void SampleLayer::Render() {
    // TODO(abekkine) : Following three lines are same for every layer.
    // TODO(abekkine) : Also, behaviour should be tested for multiple layers /w different viewports.
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(_viewport.left, _viewport.right, _viewport.bottom, _viewport.top, -1.0, 1.0);

    // Render a simple triangle.
    glColor3d(1.0, 1.0, 1.0);
    glBegin(GL_TRIANGLES);
        glVertex2d(0.0, 0.75);
        glVertex2d(0.65, -0.375);
        glVertex2d(-0.65, -0.375);
    glEnd();
}
