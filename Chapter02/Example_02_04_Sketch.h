#ifndef EXAMPLE_02_04_SKETCH_H
#define EXAMPLE_02_04_SKETCH_H

#include "../Common/P5SDL.h"
#include "Example_02_04_Mover.h"

namespace nature_of_code_chapter_02_example_04
{
    class Sketch : public P5SDL
    {
    public:
        Sketch() : P5SDL("Example 2.4: Including friction", -1, -1, 640, 240, 0) {};
        bool Setup() override;
        bool Draw() override;
    private:
        Mover       *mover_;
    };
}

#endif
