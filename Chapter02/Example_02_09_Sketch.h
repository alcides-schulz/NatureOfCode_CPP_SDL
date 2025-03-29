#ifndef EXAMPLE_02_09_SKETCH_H
#define EXAMPLE_02_09_SKETCH_H

#include "../Common/P5SDL.h"
#include "Example_02_09_Body.h"

namespace nature_of_code_chapter_02_example_09
{
    class Sketch : public P5SDL
    {
    public:
        Sketch() : P5SDL("Example 2.9: N-Body Attraction", -1, -1, 640, 240, 0) {};
        bool Setup() override;
        bool Draw() override;
    private:
        Body        *body_[10];
    };
}

#endif
