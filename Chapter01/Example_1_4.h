#ifndef EXAMPLE_1_4_H
#define EXAMPLE_1_4_H

#include "../Common/SDL_Framework.h"
#include "../Common/PVector.h"

class Example_1_4 : public SDL_Framework
{
public:
    Example_1_4() : SDL_Framework("Example 1.4: Multiplying a vector", -1, -1, 640, 240, 0) {}
    bool UserRender(int elapsed_time) override;
};

#endif

//END