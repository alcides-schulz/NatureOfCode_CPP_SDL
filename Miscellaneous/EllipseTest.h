#ifndef ELLIPSE_TEST_H
#define ELLIPSE_TEST_H

#include "../Common/P5SDL.h"

class EllipseTest : public P5SDL
{
public:
    EllipseTest() : P5SDL("Ellipse Test", -1, -1, 800, 600, 0) {}
    bool Setup() override;
    bool Draw() override;
private:
    int     _radius = 0;
};

#endif

