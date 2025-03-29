#ifndef EXAMPLE_05_04_VEHICLE_H
#define EXAMPLE_05_04_VEHICLE_H

#include "../Common/P5SDL.h"
#include "../Common/Vector.h"
#include "../Common/Utils.h"
#include "Example_05_04_FlowField.h"

namespace nature_of_code_chapter_05_example_04
{
    class Vehicle
    {
    public:
        Vehicle(int x, int y, float max_speed, float max_force)
        {
            _position = Vector(x, y);
            _velocity = Vector(0, 0);
            _acceleration = Vector(0, 0);
            _r = 4;
            _max_speed = max_speed;
            _max_force = max_force;
        };
        void Run(P5SDL *p5sdl);
        void Follow(FlowField *flowfield);
        void ApplyForce(Vector force);
        void Update(void);
        void Borders(P5SDL *p5sdl);
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
