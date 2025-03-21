#ifndef EXAMPLE_3_6_H
#define EXAMPLE_3_6_H

#include "../Common/SDL_Framework.h"

class Example_3_6 : public SDL_Framework
{
public:
    Example_3_6() : SDL_Framework("Example 3.6: Simple Harmonic Motion II", -1, -1, 640, 240, 0) {};
    bool Setup(void) override;
    bool Draw() override;
private:
    float   angle_;
    float   angle_velocity_;
};

#endif