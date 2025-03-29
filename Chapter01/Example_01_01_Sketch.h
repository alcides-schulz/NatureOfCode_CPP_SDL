#ifndef EXAMPLE_01_01_SKETCH_H
#define EXAMPLE_01_01_SKETCH_H

#include "../Common/P5SDL.h"

namespace nature_of_code_chapter_01_example_01
{
    class Sketch : public P5SDL
    {
    public:
        Sketch() : P5SDL("Example 1.1: Bouncing ball with no vectors", -1, -1, 640, 240, 0) {}
        bool Setup() override;
        bool Draw() override;
    private:
        float   x_;
        float   y_;
        float   x_speed_;
        float   y_speed_;
    };
}

#endif
