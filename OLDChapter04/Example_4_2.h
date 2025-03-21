#ifndef EXAMPLE_4_2_H
#define EXAMPLE_4_2_H

#include "../Common/SDL_Framework.h"
#include "Particle_4_2.h"

class Example_4_2 : public SDL_Framework
{
public:
    Example_4_2() : SDL_Framework("Example 4.2: An Array of Particles", -1, -1, 640, 240, 0) {};
    bool Setup(void) override;
    bool Draw(void) override;
private:
    vector<Particle_4_2 *>    particles_;
};

#endif
