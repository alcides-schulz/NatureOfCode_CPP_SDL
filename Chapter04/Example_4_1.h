#ifndef EXAMPLE_4_1_H
#define EXAMPLE_4_1_H

#include "../Common/SDL_Framework.h"

class Example_4_1 : public SDL_Framework
{
public:
    Example_4_1() : SDL_Framework("Example 4.1: DESC", -1, -1, 640, 240, 0) {};
    bool Setup(void) override;
    bool Draw(void) override;
private:
};

#endif
