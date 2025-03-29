#ifndef EXAMPLE_02_01_SKETCH_H
#define EXAMPLE_02_01_SKETCH_H

#include "../Common/P5SDL.h"
#include "Example_02_01_Mover.h"

namespace nature_of_code_chapter_02_example_01
{
    class Sketch : public P5SDL
    {
    public:
        Sketch() : P5SDL("Example 2.1: Forces", -1, -1, 640, 240, 0) {};
        bool Setup() override;
        bool Draw() override;
    private:
        Mover       *_mover;
    };
}

#endif
