#ifndef EXAMPLE_04_02_SKETCH_H
#define EXAMPLE_04_02_SKETCH_H

#include "../Common/P5SDL.h"
#include "Example_04_02_Particle.h"

namespace nature_of_code_chapter_04_example_02
{
    class Sketch : public P5SDL
    {
    public:
        Sketch() : P5SDL("Example 4.2: An Array of Particles", -1, -1, 640, 240, 0) {};
        bool Setup(void) override;
        bool Draw(void) override;
    private:
        vector<Particle *>  _particles;
    };
}

#endif
