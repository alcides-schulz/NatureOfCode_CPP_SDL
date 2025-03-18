#ifndef PARTICLE_4_3_H
#define PARTICLE_4_3_H

#include "../Common/PVector.h"
#include "../Common/SDL_Framework.h"
#include "../Common/Utils.h"

class Particle_4_3
{
public:
    Particle_4_3(int x, int y)
    {
        position_ = PVector(x, y);
        velocity_ = PVector(Utils::Random(-1, 1), Utils::Random(-2, 0));
        acceleration_ = PVector(0, 0);
        life_span_ = 255.0f;
    };
    void Update(void);
    void Show(SDL_Framework *framework);
    void ApplyForce(PVector force);
    bool IsDead(void) { return life_span_ < 0; };
    void Run(SDL_Framework *framework);
private:
    PVector position_;
    PVector velocity_;
    PVector acceleration_;
    float   life_span_;
};

#endif
