#ifndef EXAMPLE_05_03_VEHICLE_H
#define EXAMPLE_05_03_VEHICLE_H

#include "../Common/SDL_Framework.h"
#include "../Common/Vector.h"
#include "../Common/Utils.h"

namespace nature_of_code_chapter_05_example_03
{
    class Vehicle
    {
    public:
        Vehicle(int x, int y)
        {
            position_ = Vector(x, y);
            velocity_ = Vector(3, 4);
            acceleration_ = Vector(0, 0);
            r_ = 6;
            max_speed_ = 3;
            max_force_ = 0.15f;
        };
        void Update(void);
        void ApplyForce(Vector force);
        void Boundaries(SDL_Framework *framework, int offset);
        void Show(SDL_Framework *framework);
    private:
        Vector position_;
        Vector velocity_;
        Vector acceleration_;
        int     r_;
        float   max_speed_;
        float   max_force_;
    };
}

#endif
