#ifndef CIRCLE_TEST_H
#define CIRCLE_TEST_H

#include "../Common/P5SDL.h"

class CircleTest : public P5SDL
{
public:
    CircleTest() : P5SDL("Circle Test", -1, -1, 800, 600, 0) {}
    bool Setup() override;
    bool Draw() override;
private:
    int     radius_ = 0;
};

#endif

