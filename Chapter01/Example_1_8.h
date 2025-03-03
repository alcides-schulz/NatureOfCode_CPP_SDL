#ifndef EXAMPLE_1_8_H
#define EXAMPLE_1_8_H

#include "../Common/SDL_Framework.h"
#include "../Common/PVector.h"
#include "../Chapter01/Chapter01MoverV1.h"

class Example_1_8 : public SDL_Framework
{
public:
    Example_1_8() : SDL_Framework("Example 1.8: Motion 101 (velocity and constant acceleration)", 400, 100, 1200, 800, 0) {}
    bool UserInit() override;
    bool UserRender(int elapsed_time) override;
private:
    Chapter01MoverV1 *mover_;
};

#endif
