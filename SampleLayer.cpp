// Copyright 2015 A.Bekkine
#include <GL/gl.h>

#include "SampleLayer.h"

SampleLayer::SampleLayer() {}

SampleLayer::~SampleLayer() {}

void SampleLayer::Render() {
    // Render a simple triangle.
    glColor3d(1.0, 1.0, 1.0);
    glBegin(GL_TRIANGLES);
        glVertex2d(0.0, 0.75);
        glVertex2d(0.65, -0.375);
        glVertex2d(-0.65, -0.375);
    glEnd();
}
