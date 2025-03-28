#ifndef EXAMPLE_05_04_VEHICLE_H
#define EXAMPLE_05_04_VEHICLE_H

#include "../Common/SDL_Framework.h"
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
            position_ = Vector(x, y);
            velocity_ = Vector(0, 0);
            acceleration_ = Vector(0, 0);
            r_ = 4;
            max_speed_ = max_speed;
            max_force_ = max_force;
        };
        void Run(SDL_Framework *framework);
        void Follow(FlowField *flowfield);
        void ApplyForce(Vector force);
        void Update(void);
        void Borders(SDL_Framework *framework);
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
