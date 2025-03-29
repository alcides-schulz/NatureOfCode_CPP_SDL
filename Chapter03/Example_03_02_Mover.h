#ifndef EXAMPLE_03_02_MOVER_H
#define EXAMPLE_03_02_MOVER_H

#include "../Common/P5SDL.h"
#include "../Common/Vector.h"

namespace nature_of_code_chapter_03_example_02
{
    class Mover
    {
    public:
        Mover(Vector position, int mass) : position_(position), mass_(mass)
        {
            velocity_ = Vector(0, 0);
            radius_ = 8 * mass;
            acceleration_ = Vector(0, 0);
        };
        void ApplyForce(Vector force);
        void Update(void);
        void Show(P5SDL *p5sdl);
        int GetMass(void) { return mass_; };
        Vector GetPosition(void) { return position_; };
        void SetVelocity(Vector velocity) { velocity_ = velocity; };
    private:
        Vector position_;
        Vector velocity_;
        Vector acceleration_;
        int     radius_;
        int     mass_;
        float   angle_ = 0;
        float   angle_velocity_ = 0;
        float   angle_acceleration_ = 0;
    };
}

#endif
