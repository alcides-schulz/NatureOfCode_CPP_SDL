#ifndef EXAMPLE_2_9_H
#define EXAMPLE_2_9_H

#include "../Common/SDL_Framework.h"
#include "../Common/Body.h"

class Example_2_9 : public SDL_Framework
{
public:
    Example_2_9() : SDL_Framework("Example 2.9: N-Body Attraction", 400, 100, 1200, 800, 0) {};
    bool UserInit() override;
    bool UserRender(int elapsed_time) override;
private:
    Body    *body_[10];
};

#endif