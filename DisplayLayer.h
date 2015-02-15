// Copyright 2015 A.Bekkine
#ifndef DISPLAYLAYER_H_
#define DISPLAYLAYER_H_

class DisplayLayer {
 public:
    virtual ~DisplayLayer() {}
    virtual void Render() = 0;
};

#endif  // DISPLAYLAYER_H_
