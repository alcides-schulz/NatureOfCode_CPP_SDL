#ifndef EXAMPLE_3_10_H
#define EXAMPLE_3_10_H

#include "../Common/SDL_Framework.h"
#include "Bob_3_10.h"
#include "Spring_3_10.h"

class Example_3_10 : public SDL_Framework
{
public:
    Example_3_10() : SDL_Framework("Example 3.10: A Spring Connection", -1, -1, 640, 240, 0) {};
    bool UserInit(void) override;
    bool UserRender(int elapsed_time) override;
private:
    Bob_3_10    *bob_;
    Spring_3_10 *spring_;
};

#endif
