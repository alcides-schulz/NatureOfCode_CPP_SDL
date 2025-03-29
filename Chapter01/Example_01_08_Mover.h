#ifndef EXAMPLE_01_08_MOVER_H
#define EXAMPLE_01_08_MOVER_H

#include "../Common/Vector.h"
#include "../Common/P5SDL.h"

namespace nature_of_code_chapter_01_example_08
{
    class Mover
    {
    public:
        Mover(Vector position, Vector velocity);
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
