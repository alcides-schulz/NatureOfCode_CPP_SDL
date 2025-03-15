#ifndef EXAMPLE_3_1_H
#define EXAMPLE_3_1_H

#include "../Common/SDL_Framework.h"

class Example_3_1 : public SDL_Framework
{
public:
    Example_3_1() : SDL_Framework("Example 3.1: Angular Motion with rotation", -1, -1, 640, 240, 0) {};
    bool Setup(void) override;
    bool Draw() override;
private:
    float   angle_;
    float   angleVelocity_;
    float   angleAcceleration_;
};

#endif