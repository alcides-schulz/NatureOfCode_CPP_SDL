#ifndef EXAMPLE_1_10_H
#define EXAMPLE_1_10_H

#include "../Common/SDL_Framework.h"
#include "../Common/PVector.h"
#include "Mover_1_10.h"

class Example_1_10 : public SDL_Framework
{
public:
    Example_1_10() : SDL_Framework("Example 1.10: Accelerating Toward the Mouse", -1, -1, 640, 240, 0) {}
    bool Setup() override;
    bool Draw() override;
private:
    Mover_1_10  *mover_;
};

#endif
