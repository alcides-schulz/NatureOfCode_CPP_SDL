#ifndef EXAMPLE_3_9_H
#define EXAMPLE_3_9_H

#include "../Common/SDL_Framework.h"

class Example_3_9 : public SDL_Framework
{
public:
    Example_3_9() : SDL_Framework("Example 3.9: The Wave", -1, -1, 640, 240, 0) {};
    bool UserInit(void) override;
    bool UserRender(int elapsed_time) override;
private:
    float   start_angle_;
    float   angle_velocity_;
};

#endif
