#ifndef EXAMPLE_01_07_SKETCH_H
#define EXAMPLE_01_07_SKETCH_H

#include "../Common/P5SDL.h"
#include "../Common/Vector.h"
#include "Example_01_07_Mover.h"

namespace nature_of_code_chapter_01_example_07
{
    class Sketch : public P5SDL
    {
    public:
        Sketch() : P5SDL("Example 1.7: Motion 101 (velocity)", -1, -1, 640, 240, 0) {}
        bool Setup() override;
        bool Draw() override;
    private:
        Mover       *mover_;
    };
}

#endif
