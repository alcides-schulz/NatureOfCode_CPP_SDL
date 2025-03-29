#ifndef EXAMPLE_03_01_SKETCH_H
#define EXAMPLE_03_01_SKETCH_H

#include "../Common/P5SDL.h"

namespace nature_of_code_chapter_03_example_01
{
    class Sketch : public P5SDL
    {
    public:
        Sketch() : P5SDL("Example 3.1: Angular Motion with rotation", -1, -1, 640, 240, 0) {};
        bool Setup(void) override;
        bool Draw() override;
    private:
        float   _angle;
        float   _angle_velocity;
        float   _angle_acceleration;
    };
}

#endif
