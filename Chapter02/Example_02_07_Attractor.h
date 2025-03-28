#ifndef EXAMPLE_02_07_ATTRACTOR_H
#define EXAMPLE_02_07_ATTRACTOR_H

#include "../Common/SDL_Framework.h"
#include "../Common/Vector.h"
#include "Example_02_07_Mover.h"

namespace nature_of_code_chapter_02_example_07
{
    class Attractor
    {
    public:
        Attractor(Vector position, int mass) : position_(position), mass_(mass)
        {
            radius_ = mass_;
        };
        Vector Attract(Mover     *mover);
        void Show(SDL_Framework *framework);
        Vector GetPosition(void) { return position_; };
        void SetPosition(Vector position) { position_ = position; };
        int GetRadius(void) { return radius_; };
        static const int kGravity = 1;
    private:
        Vector position_;
        Vector velocity_;
        Vector acceleration_;
        int     radius_;
        int     mass_;
    };
}

#endif
