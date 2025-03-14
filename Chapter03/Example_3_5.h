#ifndef EXAMPLE_3_5_H
#define EXAMPLE_3_5_H

#include "../Common/SDL_Framework.h"

class Example_3_5 : public SDL_Framework
{
public:
    Example_3_5() : SDL_Framework("Example 3.5: Simple Harmonic Motion", -1, -1, 640, 240, 0) {};
    bool UserRender(int elapsed_time) override;
};

#endif