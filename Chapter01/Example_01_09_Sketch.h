#ifndef EXAMPLE_01_09_SKETCH_H
#define EXAMPLE_01_09_SKETCH_H

#include "../Common/P5SDL.h"
#include "../Common/Vector.h"
#include "Example_01_09_Mover.h"

namespace nature_of_code_chapter_01_example_09
{
    class Sketch : public P5SDL
    {
    public:
        Sketch() : P5SDL("Example 1.9: Motion 101 (velocity and random acceleration)", -1, -1, 640, 240, 0) {}
        bool Setup() override;
        bool Draw() override;
    private:
        Mover       *mover_;
    };
}

#endif
