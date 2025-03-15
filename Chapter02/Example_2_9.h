#ifndef EXAMPLE_2_9_H
#define EXAMPLE_2_9_H

#include "../Common/SDL_Framework.h"
#include "Body_2_9.h"

class Example_2_9 : public SDL_Framework
{
public:
    Example_2_9() : SDL_Framework("Example 2.9: N-Body Attraction", -1, -1, 640, 240, 0) {};
    bool Setup() override;
    bool Draw() override;
private:
    Body_2_9    *body_[10];
};

#endif