#ifndef EXAMPLE_05_09_VEHICLE_H
#define EXAMPLE_05_09_VEHICLE_H

#include "../Common/P5SDL.h"
#include "../Common/Vector.h"
#include "../Common/Utils.h"

namespace nature_of_code_chapter_05_example_09
{
    class Vehicle
    {
    public:
        Vehicle(P5SDL *p5sdl, int x, int y);
        void ApplyForce(Vector force);
        void Separate(vector<Vehicle *> vehicles);
        void Update(void);
        void Borders(void);
        void Show(void);
    private:
        P5SDL   *_p5sdl;
        Vector  _position;
        Vector  _velocity;
        Vector  _acceleration;
        int     _r;
        float   _max_speed;
        float   _max_force;
    };
}

#endif
