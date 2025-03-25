#ifndef CIRCLE_TEST_H
#define CIRCLE_TEST_H

#include "../Common/SDL_Framework.h"

class CircleTest : public SDL_Framework
{
public:
    CircleTest() : SDL_Framework("Circle Test", -1, -1, 800, 600, 0) {}
    bool Setup() override;
    bool Draw() override;
private:
    int     radius_ = 0;
};

#endif

