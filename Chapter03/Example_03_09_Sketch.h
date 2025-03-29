#ifndef EXAMPLE_03_09_SKETCH_H
#define EXAMPLE_03_09_SKETCH_H

#include "../Common/P5SDL.h"

namespace nature_of_code_chapter_03_example_09
{
    class Sketch : public P5SDL
    {
    public:
        Sketch() : P5SDL("Example 3.9: The Wave", -1, -1, 640, 240, 0) {};
        bool Setup(void) override;
        bool Draw() override;
    private:
        float   _start_angle;
        float   _angle_velocity;
    };
}

#endif
