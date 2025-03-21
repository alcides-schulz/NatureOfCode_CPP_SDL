#ifndef EXAMPLE_02_07_MOVER_H
#define EXAMPLE_02_07_MOVER_H

#include "../Common/SDL_Framework.h"
#include "../Common/PVector.h"

namespace nature_of_code_chapter_02_example_07
{
    class Mover
    {
    public:
        Mover(PVector position, int mass) : position_(position), mass_(mass)
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
}

#endif
