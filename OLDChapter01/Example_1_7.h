#ifndef EXAMPLE_1_7_H
#define EXAMPLE_1_7_H

#include "../Common/SDL_Framework.h"
#include "../Common/PVector.h"
#include "Mover_1_7.h"

class Example_1_7 : public SDL_Framework
{
public:
    Example_1_7() : SDL_Framework("Example 1.7: Motion 101 (velocity)", -1, -1, 640, 240, 0) {}
    bool Setup() override;
    bool Draw() override;
private:
    Mover_1_7   *mover_;
};

#endif

//END
