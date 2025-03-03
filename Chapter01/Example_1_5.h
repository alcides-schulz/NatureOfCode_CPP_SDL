#ifndef EXAMPLE_1_5_H
#define EXAMPLE_1_5_H

#include "../Common/SDL_Framework.h"
#include "../Common/PVector.h"

class Example_1_5 : public SDL_Framework
{
public:
    Example_1_5() : SDL_Framework("Example 1.5: Vector Magnitude", 400, 100, 1200, 800, 0) {}
    bool UserRender(int elapsed_time) override;
};

#endif

// END
