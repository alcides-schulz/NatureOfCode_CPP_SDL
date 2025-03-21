#ifndef EXAMPLE_02_07_ATTRACTOR_H
#define EXAMPLE_02_07_ATTRACTOR_H

#include "../Common/SDL_Framework.h"
#include "../Common/PVector.h"
#include "Example_02_07_Mover.h"

namespace nature_of_code_chapter_02_example_07
{
    class Attractor
    {
    public:
        Attractor(PVector position, int mass) : position_(position), mass_(mass)
        {
            radius_ = mass_;
        };
        PVector Attract(Mover     *mover);
        void Show(SDL_Framework *framework);
        PVector GetPosition(void) { return position_; };
        void SetPosition(PVector position) { position_ = position; };
        int GetRadius(void) { return radius_; };
        static const int kGravity = 1;
    private:
        PVector position_;
        PVector velocity_;
        PVector acceleration_;
        int     radius_;
        int     mass_;
    };
}

#endif
