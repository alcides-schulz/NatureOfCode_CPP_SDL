#ifndef EXAMPLE_05_02_VEHICLE_H
#define EXAMPLE_05_02_VEHICLE_H

#include "../Common/P5SDL.h"
#include "../Common/Vector.h"
#include "../Common/Utils.h"

namespace nature_of_code_chapter_05_example_02
{
    class Vehicle
    {
    public:
        Vehicle(int x, int y)
        {
            _position = Vector(x, y);
            _velocity = Vector(0, -2);
            _acceleration = Vector(0, 0);
            _r = 6;
            _max_speed = 4;
            _max_force = 0.1f;
        };
        void Update(void);
        void ApplyForce(Vector force);
        void Arrive(Vector target);
        void Show(P5SDL *p5sdl);
    private:
        Vector  _position;
        Vector  _velocity;
        Vector  _acceleration;
        int     _r;
        float   _max_speed;
        float   _max_force;
    };
}

#endif
