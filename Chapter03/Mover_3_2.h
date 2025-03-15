#ifndef MOVER_3_2_H
#define MOVER_3_2_H

#include "../Common/SDL_Framework.h"
#include "../Common/PVector.h"

class Mover_3_2
{
public:
    Mover_3_2(PVector position, int mass) : position_(position), mass_(mass)
    {
        velocity_ = PVector(0, 0);
        radius_ = 8 * mass;
        acceleration_ = PVector(0, 0);
    };
    void ApplyForce(PVector force);
    void Update(void);
    void Show(SDL_Framework *framework);
    int GetMass(void) { return mass_; };
    PVector GetPosition(void) { return position_; };
    void SetVelocity(PVector velocity) { velocity_ = velocity; };
private:
    PVector position_;
    PVector velocity_;
    PVector acceleration_;
    int     radius_;
    int     mass_;
    float   angle_ = 0;
    float   angle_velocity_ = 0;
    float   angle_acceleration_ = 0;
};

#endif

