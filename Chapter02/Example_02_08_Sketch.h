#ifndef EXAMPLE_02_08_SKETCH_H
#define EXAMPLE_02_08_SKETCH_H

#include "../Common/P5SDL.h"
#include "Example_02_08_Body.h"

namespace nature_of_code_chapter_02_example_08
{
    class Sketch : public P5SDL
    {
    public:
        Sketch() : P5SDL("Example 2.8: Two-Body Attraction", -1, -1, 640, 240, 0) {};
        bool Setup() override;
        bool Draw() override;
    private:
        Body    *_bodyA;
        Body    *_bodyB;
    };
}

#endif
