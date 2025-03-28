#ifndef EXAMPLE_03_03_MOVER_H
#define EXAMPLE_03_03_MOVER_H

#include "../Common/SDL_Framework.h"
#include "../Common/Vector.h"

namespace nature_of_code_chapter_03_example_03
{
    class Mover
    {
    public:
        Mover(Vector position) : position_(position)
        {
            velocity_ = Vector(0, 0);
            acceleration_ = Vector(0, 0);
            top_speed_ = 2;
        };
        void Update(SDL_Framework *framework);
        void Show(SDL_Framework *framework);
        void CheckEdges(SDL_Framework *framework);
    private:
        Vector position_;
        Vector velocity_;
        Vector acceleration_;
        float   top_speed_;
    };
}

#endif
