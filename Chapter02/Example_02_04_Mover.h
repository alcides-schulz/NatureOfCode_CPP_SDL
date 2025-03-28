#ifndef EXAMPLE_02_04_MOVER_H
#define EXAMPLE_02_04_MOVER_H

#include "../Common/SDL_Framework.h"
#include "../Common/Vector.h"

namespace nature_of_code_chapter_02_example_04
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
        int GetMass(void) { return mass_; };
        Vector GetVelocity(void) { return velocity_; };
        bool ContactEdge(SDL_Framework *framework);
        void BounceEdges(SDL_Framework *framework);
    private:
        Vector position_;
        Vector velocity_ = Vector(0, 0);
        Vector acceleration_ = Vector(0, 0);
        int     radius_;
        int     mass_;
    };
}

#endif
