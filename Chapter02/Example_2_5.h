#ifndef EXAMPLE_2_5_H
#define EXAMPLE_2_5_H

#include "../Common/SDL_Framework.h"
#include "Mover_2_5.h"
#include "Liquid_2_5.h"

class Example_2_5 : public SDL_Framework
{
public:
    Example_2_5() : SDL_Framework("Example 2.5: Fluid Resistance", -1, -1, 640, 240, 0) {};
    bool Setup() override;
    bool Draw() override;
    void Reset(void);
private:
    Mover_2_5   *mover_[10];
    Liquid_2_5  *liquid_;
};

#endif