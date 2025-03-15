#ifndef EXAMPLE_3_2_H
#define EXAMPLE_3_2_H

#include "../Common/SDL_Framework.h"
#include "Mover_3_2.h"
#include "Attractor_3_2.h"

class Example_3_2 : public SDL_Framework
{
public:
    Example_3_2() : SDL_Framework("Example 3.2: Forces with (Arbitrary) Angular Motion", -1, -1, 640, 240, 0) {};
    bool Setup() override;
    bool Draw() override;
private:
    Attractor_3_2   *attractor_;
    Mover_3_2       *mover_[10];
    bool            isDragging = false;
};

#endif