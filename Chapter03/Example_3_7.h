#ifndef EXAMPLE_3_7_H
#define EXAMPLE_3_7_H

#include "../Common/SDL_Framework.h"
#include "Oscillator_3_7.h"

class Example_3_7 : public SDL_Framework
{
public:
    Example_3_7() : SDL_Framework("Example 3.7: Oscillator Objects", -1, -1, 640, 240, 0) {};
    bool UserInit(void) override;
    bool UserRender(int elapsed_time) override;
private:
    std::vector<Oscillator_3_7 *> oscillators_;
};

#endif