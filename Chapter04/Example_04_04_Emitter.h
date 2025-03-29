#ifndef EXAMPLE_04_04_EMITTER_H
#define EXAMPLE_04_04_EMITTER_H

#include "../Common/P5SDL.h"
#include "Example_04_04_Particle.h"

namespace nature_of_code_chapter_04_example_04
{
    class Emitter
    {
    public:
        Emitter(int x, int y)
        {
            _origin = Vector(x, y);
        };
        void AddParticle(void);
        void Run(P5SDL *p5sdl);
    private:
        Vector              _origin;
        vector<Particle *>  _particles;
    };
}

#endif
