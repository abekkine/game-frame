// Copyright 2015 A.Bekkine
#ifndef VOLUME_H_
#define VOLUME_H_

class Volume {
 public:
    Volume();
    Volume(double left, double right, double bottom, double top);
    ~Volume();
    void SetWidth(double left, double right);
    void SetHeight(double bottom, double top);
    void SetDepth(double near, double far);

 private:
    double _left;
    double _right;
    double _bottom;
    double _top;
    double _near;
    double _far;
};

#endif  // VOLUME_H_
