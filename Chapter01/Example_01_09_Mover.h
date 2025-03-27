#ifndef EXAMPLE_01_09_MOVER_H
#define EXAMPLE_01_09_MOVER_H

#include "../Common/PVector.h"
#include "../Common/SDL_Framework.h"

namespace nature_of_code_chapter_01_example_09
{
    class Mover
    {
    public:
        Mover(PVector position, PVector velocity);
        void Update(void);
        void Show(SDL_Framework *framework);
        void CheckEdges(SDL_Framework *framework);
    private:
        PVector position_;
        PVector velocity_;
        PVector acceleration_;
        float   top_speed_;
    };
}

#endif
