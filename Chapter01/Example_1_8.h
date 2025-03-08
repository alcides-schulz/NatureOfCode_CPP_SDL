#ifndef EXAMPLE_1_8_H
#define EXAMPLE_1_8_H

#include "../Common/SDL_Framework.h"
#include "../Common/PVector.h"
#include "Mover_1_8.h"

class Example_1_8 : public SDL_Framework
{
public:
    Example_1_8() : SDL_Framework("Example 1.8: Motion 101 (velocity and constant acceleration)", -1, -1, 640, 240, 0) {}
    bool UserInit() override;
    bool UserRender(int elapsed_time) override;
private:
    Mover_1_8   *mover_;
};

#endif
