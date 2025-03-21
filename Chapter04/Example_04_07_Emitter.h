#ifndef EXAMPLE_04_07_EMITTER_H
#define EXAMPLE_04_07_EMITTER_H

#include "../Common/SDL_Framework.h"
#include "../Common/PVector.h"
#include "Example_04_07_Particle.h"
#include "Example_04_07_Repeller.h"

namespace nature_of_code_chapter_04_example_07
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
        void ApplyRepeller(Repeller *repeller);
        void ApplyForce(PVector force);
    private:
        PVector             origin_;
        vector<Particle *>  particles_;
    };
}

#endif
