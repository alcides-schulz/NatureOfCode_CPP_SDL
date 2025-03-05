#ifndef EXAMPLE_3_1_H
#define EXAMPLE_3_1_H

#include "../Common/SDL_Framework.h"

class Example_3_1 : public SDL_Framework
{
public:
    Example_3_1() : SDL_Framework("Example 3.1: Angular Motion with rotation.", 400, 100, 1200, 800, 0) {};
    bool UserRender(int elapsed_time) override;
private:
    float   angle_ = 0;
    float   angleVelocity_ = 0;
    float   angleAcceleration_ = 0.001f;
};

#endif