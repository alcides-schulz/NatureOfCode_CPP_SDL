#ifndef EXAMPLE_03_02_MOVER_H
#define EXAMPLE_03_02_MOVER_H

#include "../Common/P5SDL.h"
#include "../Common/Vector.h"

namespace nature_of_code_chapter_03_example_02
{
    class Mover
    {
    public:
        Mover(Vector position, int mass) : _position(position), _mass(mass)
        {
            _velocity = Vector(0, 0);
            _radius = 8 * mass;
            _acceleration = Vector(0, 0);
        };
        void ApplyForce(Vector force);
        void Update(void);
        void Show(P5SDL *p5sdl);
        int GetMass(void) { return _mass; };
        Vector GetPosition(void) { return _position; };
        void SetVelocity(Vector velocity) { _velocity = velocity; };
    private:
        Vector  _position;
        Vector  _velocity;
        Vector  _acceleration;
        int     _radius;
        int     _mass;
        float   _angle = 0;
        float   _angle_velocity = 0;
        float   _angle_acceleration = 0;
    };
}

#endif
