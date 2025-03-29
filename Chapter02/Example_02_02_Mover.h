#ifndef EXAMPLE_02_02_MOVER_H
#define EXAMPLE_02_02_MOVER_H

#include "../Common/P5SDL.h"
#include "../Common/Vector.h"

namespace nature_of_code_chapter_02_example_02
{
    class Mover
    {
    public:
        Mover(Vector position, int mass) : _position(position), _mass(mass) { };
        void ApplyForce(Vector force);
        void Update(void);
        void Show(P5SDL *p5sdl);
        void CheckEdges(P5SDL *p5sdl);
    private:
        Vector  _position;
        Vector  _velocity = Vector(0, 0);
        Vector  _acceleration = Vector(0, 0);
        int     _mass;
    };
}

#endif
