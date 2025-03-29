#ifndef EXAMPLE_02_06_SKETCH_H
#define EXAMPLE_02_06_SKETCH_H

#include "../Common/P5SDL.h"
#include "Example_02_06_Mover.h"
#include "Example_02_06_Attractor.h"

namespace nature_of_code_chapter_02_example_06
{
    class Sketch : public P5SDL
    {
    public:
        Sketch() : P5SDL("Example 2.6: Attraction", -1, -1, 640, 240, 0) {};
        bool Setup() override;
        bool Draw() override;
    private:
        Attractor       *attractor_;
        Mover           *mover_;
        bool            isDragging = false;
    };
}

#endif
