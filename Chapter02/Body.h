#ifndef BODY_H
#define BODY_H

#include "../Common/SDL_Framework.h"
#include "../Common/PVector.h"


class Body
{
public:
    Body(PVector position, int mass) : position_(position), mass_(mass)
    {
        velocity_ = PVector(0, 0);
        radius_ = 10 * mass;
        acceleration_ = PVector(0.0f, 0.0f);
    };
    void ApplyForce(PVector force);
    void Update(void);
    void Display(SDL_Framework *framework);
    void CheckEdges(SDL_Framework *framework);
    int GetMass(void) { return mass_; };
    PVector GetPosition(void) { return position_; };
    void SetVelocity(PVector velocity) { velocity_ = velocity; };
    void Attract(Body *body);
    static const int kGravity = 1;
private:
    PVector position_;
    PVector velocity_;
    PVector acceleration_;
    int     radius_;
    int     mass_;
};

#endif

