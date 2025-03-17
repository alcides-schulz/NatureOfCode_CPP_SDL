#ifndef PARTICLE_4_1_H
#define PARTICLE_4_1_H

#include "../Common/PVector.h"
#include "../Common/SDL_Framework.h"

class Particle_4_1
{
public:
    Particle_4_1(PVector location, PVector velocity) : location_(location), velocity_(velocity)
    {
        top_speed_ = 5;
    };
    void Update(void);
    void Show(SDL_Framework *framework);
    void CheckEdges(SDL_Framework *framework);
private:
    PVector location_;
    PVector velocity_;
    PVector acceleration_;
    float   top_speed_;
};

#endif
