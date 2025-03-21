#ifndef EXAMPLE_1_3_H
#define EXAMPLE_1_3_H

#include "../Common/SDL_Framework.h"
#include "../Common/PVector.h"

class Example_1_3 : public SDL_Framework
{
public:
    Example_1_3() : SDL_Framework("Example 1.3: PVector subtraction", -1, -1, 640, 240, 0) {}
    bool Draw() override;
};

#endif

//END