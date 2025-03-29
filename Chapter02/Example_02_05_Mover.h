#ifndef EXAMPLE_02_05_MOVER_H
#define EXAMPLE_02_05_MOVER_H

#include "../Common/P5SDL.h"
#include "../Common/Vector.h"

namespace nature_of_code_chapter_02_example_05
{
    class Mover
    {
    public:
        Mover(Vector position, int mass) : position_(position), mass_(mass)
        {
            radius_ = mass_ * 8;
        };
        void ApplyForce(Vector force);
        void Update(void);
        void Show(P5SDL *p5sdl);
        void CheckEdges(P5SDL *p5sdl);
        int GetMass(void) { return mass_; };
        Vector GetPosition(void) { return position_; };
        Vector GetVelocity(void) { return velocity_; };
    private:
        Vector position_;
        Vector velocity_ = Vector(0, 0);
        Vector acceleration_ = Vector(0, 0);
        int     radius_;
        int     mass_;
    };
}

#endif
