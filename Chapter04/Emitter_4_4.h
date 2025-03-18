#ifndef EMITTER_4_4_H
#define EMITTER_4_4_H

#include "../Common/SDL_Framework.h"
#include "Particle_4_4.h"

class Emitter_4_4
{
public:
    Emitter_4_4(int x, int y)
    {
        origin_ = PVector(x, y);
    };
    void AddParticle(void);
    void Run(SDL_Framework *framework);
private:
    PVector                 origin_;
    vector<Particle_4_4 *>  particles_;
};

#endif
