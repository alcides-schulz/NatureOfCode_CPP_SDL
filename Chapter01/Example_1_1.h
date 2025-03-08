#ifndef EXAMPLE_1_1_H
#define EXAMPLE_1_1_H

#include "../Common/SDL_Framework.h"

class Example_1_1 : public SDL_Framework
{
public:
    Example_1_1() : SDL_Framework("Example 1.1: Bouncing ball with no vectors", -1, -1, 400, 400, 0) {}
    bool UserRender(int elapsed_time) override;
private:
    float   x_ = 100;
    float   y_ = 100;
    float   x_speed_ = 1;
    float   y_speed_ = 3.3f;
    int     radius_ = 16;
};

#endif

// END
