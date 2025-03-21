#ifndef BODY_2_9_H
#define BODY_2_9_H

#include "../Common/SDL_Framework.h"
#include "../Common/PVector.h"

class Body_2_9
{
public:
    Body_2_9(PVector position, int mass) : position_(position), mass_(mass)
    {
        acceleration_ = PVector(0.0f, 0.0f);
    };
    void ApplyForce(PVector force);
    void Update(void);
    void Show(SDL_Framework *framework);
    int GetMass(void) { return mass_; };
    PVector GetPosition(void) { return position_; };
    void SetVelocity(PVector velocity) { velocity_ = velocity; };
    void Attract(Body_2_9 *body);

    static const int kGravity = 1;
private:
    PVector position_;
    PVector velocity_;
    PVector acceleration_;
    int     mass_;
};

#endif

