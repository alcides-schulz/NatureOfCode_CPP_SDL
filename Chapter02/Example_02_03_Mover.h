#ifndef EXAMPLE_02_03_MOVER_H
#define EXAMPLE_02_03_MOVER_H

#include "../Common/SDL_Framework.h"
#include "../Common/PVector.h"

namespace nature_of_code_chapter_02_example_03
{
    class Mover
    {
    public:
        Mover(PVector position, int mass) : position_(position), mass_(mass)
        {
            radius_ = mass_ * 8;
        };
        void ApplyForce(PVector force);
        void Update(void);
        void Show(SDL_Framework *framework);
        void CheckEdges(SDL_Framework *framework);
        int GetMass(void) { return mass_; };
    private:
        PVector position_;
        PVector velocity_ = PVector(0, 0);
        PVector acceleration_ = PVector(0, 0);
        int     mass_;
        int     radius_;
    };
}

#endif
