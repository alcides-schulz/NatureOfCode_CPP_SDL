#ifndef EXAMPLE_04_08_EMITTER_H
#define EXAMPLE_04_08_EMITTER_H

#include "../Common/P5SDL.h"
#include "../Common/Vector.h"

#include "Example_04_08_Particle.h"

namespace nature_of_code_chapter_04_example_08
{
    class Emitter
    {
    public:
        Emitter(int x, int y, SDL_Texture *texture)
        {
            origin_ = Vector(x, y);
            texture_ = texture;
        };
        void AddParticle(void);
        void ApplyForce(Vector force);
        void Run(P5SDL *p5sdl);
    private:
        Vector             origin_;
        SDL_Texture         *texture_;
        vector<Particle *>  particles_;
    };
}

#endif
