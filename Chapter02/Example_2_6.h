#ifndef EXAMPLE_2_6_H
#define EXAMPLE_2_6_H

#include "../Common/SDL_Framework.h"
#include "Mover_2_6.h"
#include "Attractor_2_6.h"

class Example_2_6 : public SDL_Framework
{
public:
    Example_2_6() : SDL_Framework("Example 2.6: Attraction", -1, -1, 640, 240, 0) {};
    bool UserInit() override;
    bool UserRender(int elapsed_time) override;
private:
    Attractor_2_6   *attractor_;
    Mover_2_6       *mover_;
    bool            isDragging = false;
};

#endif