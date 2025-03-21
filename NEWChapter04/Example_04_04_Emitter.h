#ifndef EXAMPLE_04_04_EMITTER_H
#define EXAMPLE_04_04_EMITTER_H

#include "../Common/SDL_Framework.h"
#include "Example_04_04_Particle.h"

namespace nature_of_code_chapter_04_example_04
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
