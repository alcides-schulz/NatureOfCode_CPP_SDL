#ifndef CIRCLE_TEST_H
#define CIRCLE_TEST_H

#include "../Common/SDL_Framework.h"

class CircleTest : public SDL_Framework
{
public:
    CircleTest() : SDL_Framework("Circle Test", -1, -1, 640, 240, 0) {}
    bool Draw() override;
};

#endif

