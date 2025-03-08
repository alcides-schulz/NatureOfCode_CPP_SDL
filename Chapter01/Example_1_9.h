#ifndef EXAMPLE_1_9_H
#define EXAMPLE_1_9_H

#include "../Common/SDL_Framework.h"
#include "../Common/PVector.h"
#include "Mover_1_9.h"

class Example_1_9 : public SDL_Framework
{
public:
    Example_1_9() : SDL_Framework("Example 1.9: Motion 101 (velocity and random acceleration)", -1, -1, 640, 240, 0) {}
    bool UserInit() override;
    bool UserRender(int elapsed_time) override;
private:
    Mover_1_9   *mover_;
};

#endif
