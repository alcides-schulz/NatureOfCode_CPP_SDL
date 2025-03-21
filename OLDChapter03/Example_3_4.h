#ifndef EXAMPLE_3_4_H
#define EXAMPLE_3_4_H

#include "../Common/SDL_Framework.h"

class Example_3_4 : public SDL_Framework
{
public:
    Example_3_4() : SDL_Framework("Example 3.4: Polar to cartesian", -1, -1, 640, 240, 0) {};
    bool Setup(void) override;
    bool Draw() override;
private:
    float   radius;
    float   theta;
};

#endif