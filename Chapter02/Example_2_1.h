#ifndef EXAMPLE_2_1_H
#define EXAMPLE_2_1_H

#include "../Common/SDL_Framework.h"
#include "Mover_2_1.h"

class Example_2_1 : public SDL_Framework
{
public:
    Example_2_1() : SDL_Framework("Example 2.1: Forces", -1, -1, 640, 240, 0) {};
    bool UserInit() override;
    bool UserRender(int elapsed_time) override;
private:
    Mover_2_1   *mover_;
};

#endif