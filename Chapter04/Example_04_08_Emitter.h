#ifndef EXAMPLE_04_08_EMITTER_H
#define EXAMPLE_04_08_EMITTER_H

#include "../Common/SDL_Framework.h"
#include "../Common/PVector.h"

#include "Example_04_08_Particle.h"

namespace nature_of_code_chapter_04_example_08
{
    class Emitter
    {
    public:
        Emitter(int x, int y, SDL_Texture *texture)
        {
            origin_ = PVector(x, y);
            texture_ = texture;
        };
        void AddParticle(void);
        void ApplyForce(PVector force);
        void Run(SDL_Framework *framework);
    private:
        PVector             origin_;
        SDL_Texture         *texture_;
        vector<Particle *>  particles_;
    };
}

#endif
