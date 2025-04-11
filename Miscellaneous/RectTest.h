#ifndef RECT_TEST_H
#define RECT_TEST_H

#include "../Common/P5SDL.h"
#include "../Common/Utils.h"

class RectTest : public P5SDL
{
public:
    RectTest() : P5SDL("Rectangle Test", -1, -1, 800, 600, 0) {}
    bool Setup() override;
    bool Draw() override;
private:
    int     _radius = 0;
};

#endif

