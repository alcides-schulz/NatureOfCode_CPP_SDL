#ifndef EMITTER_4_3_H
#define EMITTER_4_3_H

#include "../Common/SDL_Framework.h"
#include "Particle_4_3.h"

class Emitter_4_3
{
public:
    Emitter_4_3(int x, int y)
    {
        origin_ = PVector(x, y);
    };
    void AddParticle(void);
    void Run(SDL_Framework *framework);
private:
    PVector                 origin_;
    vector<Particle_4_3 *>  particles_;
};

#endif
