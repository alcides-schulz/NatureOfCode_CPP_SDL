#ifndef EXAMPLE_2_5_H
#define EXAMPLE_2_5_H

#include "../Common/SDL_Framework.h"
#include "Chapter02MoverV3.h"
#include "Liquid.h"

class Example_2_5 : public SDL_Framework
{
public:
    Example_2_5() : SDL_Framework("Example 2.5: Fluid Resistance", 400, 100, 1200, 800, 0) {};
    bool UserInit() override;
    bool UserRender(int elapsed_time) override;
    void Reset(void);
private:
    Chapter02MoverV3    *mover_[5];
    Liquid              *liquid_;
};

#endif