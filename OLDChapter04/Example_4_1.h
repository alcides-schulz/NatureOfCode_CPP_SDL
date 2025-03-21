#ifndef EXAMPLE_4_1_H
#define EXAMPLE_4_1_H

#include "Particle_4_1.h"

class Example_4_1 : public SDL_Framework
{
public:
    Example_4_1() : SDL_Framework("Example 4.1: Single Particle", -1, -1, 640, 240, 0) {};
    bool Setup(void) override;
    bool Draw(void) override;
private:
    Particle_4_1    *particle_;
};

#endif
