#ifndef EXAMPLE_1_4_H
#define EXAMPLE_1_4_H

#include "../../SDL_Framework.h"
#include "../Common/PVector.h"

class Example_1_4 : public SDL_Framework
{
public:
    Example_1_4() : SDL_Framework("Example 1.4: Multiplying a vector", 400, 100, 1200, 800, 0) {}
    bool UserRender(int elapsed_time) override;
};

#endif

//END