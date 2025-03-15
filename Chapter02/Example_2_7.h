#ifndef EXAMPLE_2_7_H
#define EXAMPLE_2_7_H

#include "../Common/SDL_Framework.h"
#include "Mover_2_7.h"
#include "Attractor_2_7.h"

class Example_2_7 : public SDL_Framework
{
public:
    Example_2_7() : SDL_Framework("Example 2.7: Attraction with many movers", -1, -1, 640, 240, 0) {};
    bool Setup() override;
    bool Draw() override;
private:
    Attractor_2_7   *attractor_;
    Mover_2_7       *mover_[10];
    bool            isDragging = false;
};

#endif