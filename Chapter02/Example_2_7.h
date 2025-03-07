#ifndef EXAMPLE_2_7_H
#define EXAMPLE_2_7_H

#include "../Common/SDL_Framework.h"
#include "Chapter02MoverV1.h"
#include "../Common/Attractor.h"

class Example_2_7 : public SDL_Framework
{
public:
    Example_2_7() : SDL_Framework("Example 2.7: Attraction with many movers", 400, 100, 1200, 800, 0) {};
    bool UserInit() override;
    bool UserRender(int elapsed_time) override;
private:
    Attractor           *attractor_;
    Chapter02MoverV1    *mover_[10];
    bool                isDragging = false;
};

#endif