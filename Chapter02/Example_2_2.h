#ifndef EXAMPLE_2_2_H
#define EXAMPLE_2_2_H

#include "../Common/SDL_Framework.h"
#include "Mover_2_2.h"

class Example_2_2 : public SDL_Framework
{
public:
    Example_2_2() : SDL_Framework("Example 2.2: Forces on 2 objects", -1, -1, 640, 240, 0) {};
    bool UserInit() override;
    bool UserRender(int elapsed_time) override;
private:
    Mover_2_2   *moverA_;
    Mover_2_2   *moverB_;
};

#endif