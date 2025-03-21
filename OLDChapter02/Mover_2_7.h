#ifndef MOVER_2_7_H
#define MOVER_2_7_H

#include "../Common/SDL_Framework.h"
#include "../Common/PVector.h"

class Mover_2_7
{
public:
    Mover_2_7(PVector position, int mass) : position_(position), mass_(mass)
    {
        radius_ = mass_ * 8;
        velocity_ = PVector(1, 0);
        acceleration_ = PVector(0, 0);
    };
    void ApplyForce(PVector force);
    void Update(void);
    void Show(SDL_Framework *framework);
    int GetMass(void) { return mass_; };
    PVector GetPosition(void) { return position_; };
    PVector GetVelocity(void) { return velocity_; };
private:
    PVector position_;
    PVector velocity_;
    PVector acceleration_;
    int     radius_;
    int     mass_;
};

#endif

