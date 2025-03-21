#ifndef EXAMPLE_4_3_H
#define EXAMPLE_4_3_H

#include "../Common/SDL_Framework.h"
#include "Emitter_4_3.h"

class Example_4_3 : public SDL_Framework
{
public:
    Example_4_3() : SDL_Framework("Example 4.3: A Single Particle Emitter", -1, -1, 640, 240, 0) {};
    bool Setup(void) override;
    bool Draw(void) override;
private:
    Emitter_4_3     *emitter_;
};

#endif
