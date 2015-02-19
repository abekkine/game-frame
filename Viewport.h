// Copyright 2015 A.Bekkine
#ifndef VIEWPORT_H_
#define VIEWPORT_H_

class Viewport {
 public:
    Viewport();
    Viewport(double l, double r, double b, double t);
    ~Viewport();
    void SetWidth(double l, double r);
    void SetHeight(double b, double t);
    void SetDepth(double n, double f);
    // UPDATE
    void InitVariables();
    void Update(double delta_x, double delta_y, double delta_zoom);
    // END
 public:
    double left;
    double right;
    double bottom;
    double top;
    double near;
    double far;

 private:
    double _zoom_level;
    double _scale_x;
    double _scale_y;
    double _center_x;
    double _center_y;
    double _world_width;
    double _world_height;
    double _screen_width;
    double _screen_height;
};

#endif  // VIEWPORT_H_
