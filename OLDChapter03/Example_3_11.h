#ifndef EXAMPLE_3_11_H
#define EXAMPLE_3_11_H

#include "../Common/SDL_Framework.h"
#include "Pendulum_3_11.h"

class Example_3_11 : public SDL_Framework
{
public:
    Example_3_11() : SDL_Framework("Example 3.11: Swinging Pendulum", -1, -1, 640, 240, 0) {};
    bool Setup(void) override;
    bool Draw(void) override;
private:
    Pendulum_3_11   *pendulum_;
};

#endif
