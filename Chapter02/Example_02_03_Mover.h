#ifndef EXAMPLE_02_03_MOVER_H
#define EXAMPLE_02_03_MOVER_H

#include "../Common/SDL_Framework.h"
#include "../Common/Vector.h"

namespace nature_of_code_chapter_02_example_03
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
        void Show(SDL_Framework *framework);
        void CheckEdges(SDL_Framework *framework);
        int GetMass(void) { return mass_; };
    private:
        Vector position_;
        Vector velocity_ = Vector(0, 0);
        Vector acceleration_ = Vector(0, 0);
        int     mass_;
        int     radius_;
    };
}

#endif
