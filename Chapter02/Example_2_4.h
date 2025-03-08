#ifndef EXAMPLE_2_4_H
#define EXAMPLE_2_4_H

#include "../Common/SDL_Framework.h"
#include "Mover_2_4.h"

class Example_2_4 : public SDL_Framework
{
public:
    Example_2_4() : SDL_Framework("Example 2.4: Including friction", -1, -1, 640, 240, 0) {};
    bool UserInit() override;
    bool UserRender(int elapsed_time) override;
private:
    Mover_2_4   *mover_;
};

#endif