#ifndef EXAMPLE_02_06_ATTRACTOR_H
#define EXAMPLE_02_06_ATTRACTOR_H

#include "../Common/SDL_Framework.h"
#include "../Common/Vector.h"
#include "Example_02_06_Mover.h"

namespace nature_of_code_chapter_02_example_06
{
    class Attractor
    {
    public:
        Attractor(Vector position, int mass) : position_(position), mass_(mass) { };
        Vector Attract(Mover     *mover);
        void Show(SDL_Framework *framework);
        Vector GetPosition(void) { return position_; };
        void SetPosition(Vector position) { position_ = position; };
        int GetRadius(void) { return mass_; };
        static const int kGravity = 1;
    private:
        Vector position_;
        Vector velocity_;
        Vector acceleration_;
        int     mass_;
    };
}

#endif
