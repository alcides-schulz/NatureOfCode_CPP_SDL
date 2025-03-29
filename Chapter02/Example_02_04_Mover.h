#ifndef EXAMPLE_02_04_MOVER_H
#define EXAMPLE_02_04_MOVER_H

#include "../Common/P5SDL.h"
#include "../Common/Vector.h"

namespace nature_of_code_chapter_02_example_04
{
    class Mover
    {
    public:
        Mover(Vector position, int mass) : _position(position), _mass(mass)
        {
            _radius = _mass * 8;
        };
        void ApplyForce(Vector force);
        void Update(void);
        void Show(P5SDL *p5sdl);
        int GetMass(void) { return _mass; };
        Vector GetVelocity(void) { return _velocity; };
        bool ContactEdge(P5SDL *p5sdl);
        void BounceEdges(P5SDL *p5sdl);
    private:
        Vector  _position;
        Vector  _velocity = Vector(0, 0);
        Vector  _acceleration = Vector(0, 0);
        int     _radius;
        int     _mass;
    };
}

#endif
