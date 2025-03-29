#ifndef EXAMPLE_01_10_MOVER_H
#define EXAMPLE_01_10_MOVER_H

#include "../Common/Vector.h"
#include "../Common/P5SDL.h"

namespace nature_of_code_chapter_01_example_10
{
    class Mover
    {
    public:
        Mover(Vector position, Vector velocity) : position_(position), velocity_(velocity)
        {
            acceleration_ = Vector(0, 0);
            top_speed_ = 2;
        };
        void Update(void);
        void Show(P5SDL *p5sdl);
        void CheckEdges(P5SDL *p5sdl);
        Vector GetPosition(void) { return position_; };
        void SetAcceleration(Vector acceleration) { acceleration_ = acceleration; };
    private:
        Vector position_;
        Vector velocity_;
        Vector acceleration_;
        float   top_speed_;
    };
}

#endif
