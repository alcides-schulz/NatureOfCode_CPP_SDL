#ifndef EXAMPLE_04_07_SKETCH_H
#define EXAMPLE_04_07_SKETCH_H

#include "../Common/P5SDL.h"
#include "Example_04_07_Emitter.h"
#include "Example_04_07_Repeller.h"

namespace nature_of_code_chapter_04_example_07
{
    class Sketch : public P5SDL
    {
    public:
        Sketch() : P5SDL("Example 4.7: A Particle System with Repellers", -1, -1, 640, 240, 0) {};
        bool Setup(void) override;
        bool Draw(void) override;
    private:
        Emitter     *_emitter;
        Repeller    *_repeller;
    };
}

#endif
