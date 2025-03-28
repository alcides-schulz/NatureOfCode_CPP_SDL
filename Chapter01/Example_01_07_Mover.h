#ifndef EXAMPLE_01_07_MOVER_H
#define EXAMPLE_01_07_MOVER_H

#include "../Common/Vector.h"
#include "../Common/SDL_Framework.h"

namespace nature_of_code_chapter_01_example_07
{
    class Mover
    {
    public:
        Mover(Vector position, Vector velocity) : position_(position), velocity_(velocity) { };
        void Update(void);
        void Show(SDL_Framework *framework);
        void CheckEdges(SDL_Framework *framework);
    private:
        Vector position_;
        Vector velocity_;
    };
}

#endif
