#ifndef EXAMPLE_04_01_SKETCH_H
#define EXAMPLE_04_01_SKETCH_H

#include "Example_04_01_Particle.h"

namespace nature_of_code_chapter_04_example_01
{
    class Sketch : public P5SDL
    {
    public:
        Sketch() : P5SDL("Example 4.1: Single Particle", -1, -1, 640, 240, 0) {};
        bool Setup(void) override;
        bool Draw(void) override;
    private:
        Particle        *particle_;
    };
}

#endif
