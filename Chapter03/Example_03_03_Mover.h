#ifndef EXAMPLE_03_03_MOVER_H
#define EXAMPLE_03_03_MOVER_H

#include "../Common/P5SDL.h"
#include "../Common/Vector.h"

namespace nature_of_code_chapter_03_example_03
{
    class Mover
    {
    public:
        Mover(Vector position) : _position(position)
        {
            _velocity = Vector(0, 0);
            _acceleration = Vector(0, 0);
            _top_speed = 2;
        };
        void Update(P5SDL *p5sdl);
        void Show(P5SDL *p5sdl);
        void CheckEdges(P5SDL *p5sdl);
    private:
        Vector  _position;
        Vector  _velocity;
        Vector  _acceleration;
        float   _top_speed;
    };
}

#endif
