#ifndef EXAMPLE_02_05_SKETCH_H
#define EXAMPLE_02_05_SKETCH_H

#include "../Common/P5SDL.h"
#include "Example_02_05_Mover.h"
#include "Example_02_05_Liquid.h"

namespace nature_of_code_chapter_02_example_05
{
    class Sketch : public P5SDL
    {
    public:
        Sketch() : P5SDL("Example 2.5: Fluid Resistance", -1, -1, 640, 240, 0) {};
        bool Setup() override;
        bool Draw() override;
        void Reset(void);
    private:
        Mover   *_mover[10];
        Liquid  *_liquid;
    };
}

#endif
