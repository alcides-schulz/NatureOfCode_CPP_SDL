#ifndef EXAMPLE_02_02_SKETCH_H
#define EXAMPLE_02_02_SKETCH_H

#include "../Common/P5SDL.h"
#include "Example_02_02_Mover.h"

namespace nature_of_code_chapter_02_example_02
{
    class Sketch : public P5SDL
    {
    public:
        Sketch() : P5SDL("Example 2.2: Forces on 2 objects", -1, -1, 640, 240, 0) {};
        bool Setup() override;
        bool Draw() override;
    private:
        Mover   *_moverA;
        Mover   *_moverB;
    };
}

#endif
