#ifndef EXAMPLE_05_09_VEHICLE_H
#define EXAMPLE_05_09_VEHICLE_H

#include "../Common/SDL_Framework.h"
#include "../Common/Vector.h"
#include "../Common/Utils.h"

namespace nature_of_code_chapter_05_example_09
{
    class Vehicle
    {
    public:
        Vehicle(SDL_Framework *framework, int x, int y, float max_speed, float max_force);
        void Run();
        void Update(void);
        void ApplyForce(Vector force);
        void Borders();
        void Show();
    private:
        SDL_Framework   *framework_;
        Vector position_;
        Vector velocity_;
        Vector acceleration_;
        int     r_;
        float   max_speed_;
        float   max_force_;
    };
}

#endif
