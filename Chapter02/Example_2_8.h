#ifndef EXAMPLE_2_8_H
#define EXAMPLE_2_8_H

#include "../Common/SDL_Framework.h"
#include "Body_2_8.h"

class Example_2_8 : public SDL_Framework
{
public:
    Example_2_8() : SDL_Framework("Example 2.8: Two-Body Attraction", -1, -1, 640, 240, 0) {};
    bool UserInit() override;
    bool UserRender(int elapsed_time) override;
private:
    Body_2_8    *bodyA_;
    Body_2_8    *bodyB_;
};

#endif