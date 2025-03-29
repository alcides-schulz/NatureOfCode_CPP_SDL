#ifndef EXAMPLE_01_08_SKETCH_H
#define EXAMPLE_01_08_SKETCH_H

#include "../Common/P5SDL.h"
#include "../Common/Vector.h"
#include "Example_01_08_Mover.h"

namespace nature_of_code_chapter_01_example_08
{
    class Sketch : public P5SDL
    {
    public:
        Sketch() : P5SDL("Example 1.8: Motion 101 (velocity and constant acceleration)", -1, -1, 640, 240, 0) {}
        bool Setup() override;
        bool Draw() override;
    private:
        Mover       *mover_;
    };
}

#endif
