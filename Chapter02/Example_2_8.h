#ifndef EXAMPLE_2_8_H
#define EXAMPLE_2_8_H

#include "../Common/SDL_Framework.h"
#include "Body.h"

class Example_2_8 : public SDL_Framework
{
public:
    Example_2_8() : SDL_Framework("Example 2.8: Two-Body Attraction", 400, 100, 1200, 800, 0) {};
    bool UserInit() override;
    bool UserRender(int elapsed_time) override;
private:
    Body    *bodyA_;
    Body    *bodyB_;
};

#endif