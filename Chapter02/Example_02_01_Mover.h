#ifndef EXAMPLE_02_01_MOVER_H
#define EXAMPLE_02_01_MOVER_H

#include "../Common/SDL_Framework.h"
#include "../Common/Vector.h"

namespace nature_of_code_chapter_02_example_01
{
    class Mover
    {
    public:
        Mover(Vector position, int mass) : position_(position), mass_(mass) {};
        void ApplyForce(Vector force);
        void Update(void);
        void Show(SDL_Framework *framework);
        void CheckEdges(SDL_Framework *framework);
    private:
        Vector position_;
        Vector velocity_ = Vector(0, 0);
        Vector acceleration_ = Vector(0, 0);
        int     mass_;
    };
}

#endif
