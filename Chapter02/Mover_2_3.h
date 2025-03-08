#ifndef MOVER_2_3_H
#define MOVER_2_3_H

#include "../Common/SDL_Framework.h"
#include "../Common/PVector.h"

class Mover_2_3
{
public:
    Mover_2_3(PVector position, int mass) : position_(position), mass_(mass)
    {
        radius_ = mass_ * 8;
    };
    void ApplyForce(PVector force);
    void Update(void);
    void Display(SDL_Framework *framework);
    void CheckEdges(SDL_Framework *framework);
    int GetMass(void) { return mass_; };
private:
    PVector position_;
    PVector velocity_ = PVector(0, 0);
    PVector acceleration_ = PVector(0, 0);
    int     radius_;
    int     mass_;
};

#endif

