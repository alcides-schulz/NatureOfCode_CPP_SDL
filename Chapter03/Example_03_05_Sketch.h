#ifndef EXAMPLE_03_05_SKETCH_H
#define EXAMPLE_03_05_SKETCH_H

#include "../Common/P5SDL.h"

namespace nature_of_code_chapter_03_example_05
{
    class Sketch : public P5SDL
    {
    public:
        Sketch() : P5SDL("Example 3.5: Simple Harmonic Motion", -1, -1, 640, 240, 0) {};
        bool Draw() override;
    };
}

#endif
