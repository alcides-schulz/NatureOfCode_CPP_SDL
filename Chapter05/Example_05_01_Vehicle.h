#ifndef EXAMPLE_05_01_VEHICLE_H
#define EXAMPLE_05_01_VEHICLE_H

#include "../Common/SDL_Framework.h"
#include "../Common/Vector.h"

namespace nature_of_code_chapter_05_example_01
{
    class Vehicle
    {
    public:
        Vehicle(int x, int y)
        {
            position_ = Vector(x, y);
            velocity_ = Vector(0, 0);
            acceleration_ = Vector(0, 0);
            r_ = 6;
            max_speed_ = 8;
            max_force_ = 0.2f;
        };
        void Update(void);
        void ApplyForce(Vector force);
        void Seek(Vector target);
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
