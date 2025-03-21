#ifndef EXAMPLE_4_5_EMITTER_H
#define EXAMPLE_4_5_EMITTER_H

#include "../Common/SDL_Framework.h"
#include "../Common/PVector.h"

#include "Example_04_05_Particle.h"
#include "Example_04_05_Confetti.h"

namespace nature_of_code_chapter_04_example_05
{
    class Emitter
    {
    public:
        Emitter(int x, int y)
        {
            origin_ = PVector(x, y);
        };
        void AddParticle(void);
        void Run(SDL_Framework *framework);
    private:
        PVector             origin_;
        vector<Particle *>  particles_;
    };
}

#endif
