#ifndef EXAMPLE_04_06_EMITTER_H
#define EXAMPLE_04_06_EMITTER_H

#include "../Common/P5SDL.h"
#include "../Common/Vector.h"

#include "Example_04_06_Particle.h"

namespace nature_of_code_chapter_04_example_06
{
    class Emitter
    {
    public:
        Emitter(int x, int y)
        {
            origin_ = Vector(x, y);
        };
        void AddParticle(void);
        void Run(P5SDL *p5sdl);
    private:
        Vector             origin_;
        vector<Particle *>  particles_;
    };
}

#endif
