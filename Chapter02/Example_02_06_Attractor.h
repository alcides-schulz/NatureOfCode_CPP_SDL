#ifndef EXAMPLE_02_06_ATTRACTOR_H
#define EXAMPLE_02_06_ATTRACTOR_H

#include "../Common/SDL_Framework.h"
#include "../Common/PVector.h"
#include "Example_02_06_Mover.h"

namespace nature_of_code_chapter_02_example_06
{
    class Attractor
    {
    public:
        Attractor(PVector position, int mass) : position_(position), mass_(mass) { };
        PVector Attract(Mover     *mover);
        void Show(SDL_Framework *framework);
        PVector GetPosition(void) { return position_; };
        void SetPosition(PVector position) { position_ = position; };
        int GetRadius(void) { return mass_; };
        static const int kGravity = 1;
    private:
        PVector position_;
        PVector velocity_;
        PVector acceleration_;
        int     mass_;
    };
}

#endif
