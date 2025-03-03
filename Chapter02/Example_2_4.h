#ifndef EXAMPLE_2_4_H
#define EXAMPLE_2_4_H

#include "../Common/SDL_Framework.h"
#include "Chapter02MoverV2.h"

class Example_2_4 : public SDL_Framework
{
public:
    Example_2_4() : SDL_Framework("Example 2.4: Including friction", 400, 100, 1200, 800, 0) {};
    bool UserInit() override;
    bool UserRender(int elapsed_time) override;
private:
    Chapter02MoverV2 *mover_;
};

#endif