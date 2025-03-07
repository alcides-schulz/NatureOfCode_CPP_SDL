#ifndef EXAMPLE_2_6_H
#define EXAMPLE_2_6_H

#include "../Common/SDL_Framework.h"
#include "Chapter02MoverV1.h"
#include "../Common/Attractor.h"

class Example_2_6 : public SDL_Framework
{
public:
    Example_2_6() : SDL_Framework("Example 2.6: Attraction", 400, 100, 1200, 800, 0) {};
    bool UserInit() override;
    bool UserRender(int elapsed_time) override;
private:
    Attractor           *attractor_;
    Chapter02MoverV1    *mover_;
    bool                isDragging = false;
};

#endif