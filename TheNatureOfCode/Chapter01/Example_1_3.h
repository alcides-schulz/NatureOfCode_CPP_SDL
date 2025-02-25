#ifndef EXAMPLE_1_3_H
#define EXAMPLE_1_3_H

#include "../../SDL_Framework.h"
#include "../Common/PVector.h"

class Example_1_3 : public SDL_Framework
{
public:
    Example_1_3() : SDL_Framework("Example 1.3: PVector subtraction", 400, 100, 1200, 800, 0) {}
    bool UserRender(int elapsed_time) override;
};

#endif

//END