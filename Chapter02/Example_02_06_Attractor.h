#ifndef EXAMPLE_02_06_ATTRACTOR_H
#define EXAMPLE_02_06_ATTRACTOR_H

#include "../Common/P5SDL.h"
#include "../Common/Vector.h"
#include "Example_02_06_Mover.h"

namespace nature_of_code_chapter_02_example_06
{
    class Attractor
    {
    public:
        Attractor(Vector position, int mass) : _position(position), _mass(mass) { };
        Vector Attract(Mover     *mover);
        void Show(P5SDL *p5sdl);
        Vector GetPosition(void) { return _position; };
        void SetPosition(Vector position) { _position = position; };
        int GetRadius(void) { return _mass; };
        static const int kGravity = 1;
    private:
        Vector  _position;
        Vector  _velocity;
        Vector  _acceleration;
        int     _mass;
    };
}

#endif
