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
        float angle_ = 0;
        float angle_velocity_ = 0.2f;
        float amplitude_ = 100;
    };
}

#endif
