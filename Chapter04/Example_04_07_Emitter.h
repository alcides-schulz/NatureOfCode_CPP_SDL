#ifndef EXAMPLE_04_07_EMITTER_H
#define EXAMPLE_04_07_EMITTER_H

#include "../Common/P5SDL.h"
#include "../Common/Vector.h"
#include "Example_04_07_Particle.h"
#include "Example_04_07_Repeller.h"

namespace nature_of_code_chapter_04_example_07
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
        void ApplyRepeller(Repeller *repeller);
        void ApplyForce(Vector force);
    private:
        Vector              _origin;
        vector<Particle *>  _particles;
    };
}

#endif
