#ifndef EXAMPLE_02_08_BODY_H
#define EXAMPLE_02_08_BODY_H

#include "../Common/P5SDL.h"
#include "../Common/Vector.h"

namespace nature_of_code_chapter_02_example_08
{
    class Body
    {
    public:
        Body(Vector position, int mass) : _position(position), _mass(mass)
        {
            _radius = (int)(std::sqrtf((float)_mass) * 2.0f);
            _acceleration = Vector(0.0f, 0.0f);
        };
        void ApplyForce(Vector force);
        void Update(void);
        void Show(P5SDL *p5sdl);
        int GetMass(void) { return _mass; };
        Vector GetPosition(void) { return _position; };
        void SetVelocity(Vector velocity) { _velocity = velocity; };
        void Attract(Body *body);
        static const int kGravity = 1;
    private:
        Vector  _position;
        Vector  _velocity;
        Vector  _acceleration;
        int     _radius;
        int     _mass;
    };
}

#endif
