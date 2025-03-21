#ifndef EXAMPLE_01_08_MOVER_H
#define EXAMPLE_01_08_MOVER_H

#include "../Common/PVector.h"
#include "../Common/SDL_Framework.h"

namespace nature_of_code_chapter_01_example_08
{
    class Mover
    {
    public:
        Mover(PVector position, PVector velocity) : position_(position), velocity_(velocity)
        {
            acceleration_ = PVector(0, 0);
            top_speed_ = 10;
        };
        void Update(void);
        void Show(SDL_Framework *framework);
        void CheckEdges(SDL_Framework *framework);
        PVector GetPosition(void) { return position_; };
        void SetAcceleration(PVector acceleration) { acceleration_ = acceleration; };
    private:
        PVector position_;
        PVector velocity_;
        PVector acceleration_;
        float   top_speed_;
    };
}

#endif
