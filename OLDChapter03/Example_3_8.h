#ifndef EXAMPLE_3_8_H
#define EXAMPLE_3_8_H

#include "../Common/SDL_Framework.h"

class Example_3_8 : public SDL_Framework
{
public:
    Example_3_8() : SDL_Framework("Example 3.8: Static Wave", -1, -1, 640, 240, 0) {};
    bool Setup(void) override;
private:
    float angle_ = 0;
    float angle_velocity_ = 0.2f;
    float amplitude_ = 100;
};

#endif
