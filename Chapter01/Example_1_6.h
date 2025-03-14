#ifndef EXAMPLE_1_6_H
#define EXAMPLE_1_6_H

#include "../Common/SDL_Framework.h"
#include "../Common/PVector.h"

class Example_1_6 : public SDL_Framework
{
public:
    Example_1_6() : SDL_Framework("Example 1.6: Normalizing a vector", -1, -1, 640, 240, 0) {}
    bool Draw() override;
};

#endif

// END
