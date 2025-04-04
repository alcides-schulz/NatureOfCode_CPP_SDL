#ifndef EXAMPLE_01_07_MOVER_H
#define EXAMPLE_01_07_MOVER_H

#include "../Common/Vector.h"
#include "../Common/P5SDL.h"

namespace nature_of_code_chapter_01_example_07
{
    class Mover
    {
    public:
        Mover(Vector position, Vector velocity) : _position(position), _velocity(velocity) { };
        void Update(void);
        void Show(P5SDL *p5sdl);
        void CheckEdges(P5SDL *p5sdl);
    private:
        Vector _position;
        Vector _velocity;
    };
}

#endif
