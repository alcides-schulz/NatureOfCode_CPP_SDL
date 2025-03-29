#ifndef EXAMPLE_05_01_VEHICLE_H
#define EXAMPLE_05_01_VEHICLE_H

#include "../Common/P5SDL.h"
#include "../Common/Vector.h"

namespace nature_of_code_chapter_05_example_01
{
    class Vehicle
    {
    public:
        Vehicle(int x, int y)
        {
            _position = Vector(x, y);
            _velocity = Vector(0, 0);
            _acceleration = Vector(0, 0);
            _r = 6;
            _max_speed = 8;
            _max_force = 0.2f;
        };
        void Update(void);
        void ApplyForce(Vector force);
        void Seek(Vector target);
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
