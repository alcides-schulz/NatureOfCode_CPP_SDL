#ifndef EXAMPLE_01_05_SKETCH_H
#define EXAMPLE_01_05_SKETCH_H

#include "../Common/P5SDL.h"
#include "../Common/Vector.h"

namespace nature_of_code_chapter_01_example_05
{
    class Sketch : public P5SDL
    {
    public:
        Sketch() : P5SDL("Example 1.5: Vector Magnitude", -1, -1, 640, 240, 0) {}
        bool Draw() override;
    };
}

#endif
