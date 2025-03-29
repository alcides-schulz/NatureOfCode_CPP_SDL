#ifndef EXAMPLE_03_08_SKETCH_H
#define EXAMPLE_03_08_SKETCH_H

#include "../Common/P5SDL.h"

namespace nature_of_code_chapter_03_example_08
{
    class Sketch : public P5SDL
    {
    public:
        Sketch() : P5SDL("Example 3.8: Static Wave", -1, -1, 640, 240, 0) {};
        bool Setup(void) override;
    private:
        float _angle = 0;
        float _angle_velocity = 0.2f;
        float _amplitude = 100;
    };
}

#endif
