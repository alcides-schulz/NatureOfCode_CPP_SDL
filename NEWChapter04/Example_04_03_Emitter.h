#ifndef EXAMPLE_04_03_EMITTER_H
#define EXAMPLE_04_03_EMITTER_H

#include "../Common/SDL_Framework.h"
#include "Example_04_03_Particle.h"

namespace nature_of_code_chapter_04_example_03
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
        PVector                 origin_;
        vector<Particle     *>  particles_;
    };
}

#endif
