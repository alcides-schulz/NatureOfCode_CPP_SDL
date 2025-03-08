#ifndef EXAMPLE_2_3_H
#define EXAMPLE_2_3_H

#include "../Common/SDL_Framework.h"
#include "Mover_2_3.h"

class Example_2_3 : public SDL_Framework
{
public:
    Example_2_3() : SDL_Framework("Example 2.3: Gravity scaled by Mass", -1, -1, 640, 240, 0) {};
    bool UserInit() override;
    bool UserRender(int elapsed_time) override;
private:
    Mover_2_3   *moverA_;
    Mover_2_3   *moverB_;
};

#endif