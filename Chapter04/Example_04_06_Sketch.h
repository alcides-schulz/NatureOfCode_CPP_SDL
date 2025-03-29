#ifndef EXAMPLE_04_06_SKETCH_H
#define EXAMPLE_04_06_SKETCH_H

#include "../Common/P5SDL.h"
#include "Example_04_06_Emitter.h"

namespace nature_of_code_chapter_04_example_06
{
    class Sketch : public P5SDL
    {
    public:
        Sketch() : P5SDL("Example 4.6: A Particle System with Forces", -1, -1, 640, 240, 0) {};
        bool Setup(void) override;
        bool Draw(void) override;
    private:
        Emitter     *emitter_;
    };
}

#endif
