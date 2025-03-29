#ifndef EXAMPLE_02_07_SKETCH_H
#define EXAMPLE_02_07_SKETCH_H

#include "../Common/P5SDL.h"
#include "Example_02_07_Mover.h"
#include "Example_02_07_Attractor.h"

namespace nature_of_code_chapter_02_example_07
{
    class Sketch : public P5SDL
    {
    public:
        Sketch() : P5SDL("Example 2.7: Attraction with many movers", -1, -1, 640, 240, 0) {};
        bool Setup() override;
        bool Draw() override;
    private:
        Attractor   *_attractor;
        Mover       *_mover[10];
        bool        _is_dragging = false;
    };
}

#endif
