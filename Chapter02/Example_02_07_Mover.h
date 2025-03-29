#ifndef EXAMPLE_02_07_MOVER_H
#define EXAMPLE_02_07_MOVER_H

#include "../Common/P5SDL.h"
#include "../Common/Vector.h"

namespace nature_of_code_chapter_02_example_07
{
    class Mover
    {
    public:
        Mover(Vector position, int mass) : position_(position), mass_(mass)
        {
            radius_ = mass_ * 8;
            velocity_ = Vector(1, 0);
            acceleration_ = Vector(0, 0);
        };
        void ApplyForce(Vector force);
        void Update(void);
        void Show(P5SDL *p5sdl);
        int GetMass(void) { return mass_; };
        Vector GetPosition(void) { return position_; };
        Vector GetVelocity(void) { return velocity_; };
    private:
        Vector position_;
        Vector velocity_;
        Vector acceleration_;
        int     radius_;
        int     mass_;
    };
}

#endif
