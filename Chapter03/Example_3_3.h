#ifndef EXAMPLE_3_3_H
#define EXAMPLE_3_3_H

#include "../Common/SDL_Framework.h"
#include "Mover_3_3.h"

class Example_3_3 : public SDL_Framework
{
public:
    Example_3_3() : SDL_Framework("Example 3.3: Pointing in the direction of motion.", -1, -1, 640, 240, 0) {};
    bool UserInit(void) override;
    bool UserRender(int elapsed_time) override;
private:
    Mover_3_3       *mover_;
};

#endif