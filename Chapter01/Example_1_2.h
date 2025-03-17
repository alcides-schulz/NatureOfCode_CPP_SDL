#ifndef EXAMPLE_1_2_H
#define EXAMPLE_1_2_H

#include "../Common/SDL_Framework.h"
#include "../Common/PVector.h"

class Example_1_2 : public SDL_Framework
{
public:
    Example_1_2() : SDL_Framework("Example 1.2: Bouncing ball with PVectors", -1, -1, 640, 240, 0) {}
    bool Setup() override;
    bool Draw() override;
private:
    PVector position_;
    PVector velocity_;
};

#endif

// END
