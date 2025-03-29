#ifndef EXAMPLE_02_07_MOVER_H
#define EXAMPLE_02_07_MOVER_H

#include "../Common/P5SDL.h"
#include "../Common/Vector.h"

namespace nature_of_code_chapter_02_example_07
{
    class Mover
    {
    public:
        Mover(Vector position, int mass) : _position(position), _mass(mass)
        {
            _radius = _mass * 8;
            _velocity = Vector(1, 0);
            _acceleration = Vector(0, 0);
        };
        void ApplyForce(Vector force);
        void Update(void);
        void Show(P5SDL *p5sdl);
        int GetMass(void) { return _mass; };
        Vector GetPosition(void) { return _position; };
        Vector GetVelocity(void) { return _velocity; };
    private:
        Vector  _position;
        Vector  _velocity;
        Vector  _acceleration;
        int     _radius;
        int     _mass;
    };
}

#endif
