#ifndef EXAMPLE_05_06_VEHICLE_H
#define EXAMPLE_05_06_VEHICLE_H

#include "../Common/P5SDL.h"
#include "../Common/Vector.h"
#include "../Common/Utils.h"
#include "Example_05_06_Path.h"

namespace nature_of_code_chapter_05_example_06
{
    class Vehicle
    {
    public:
        Vehicle(int x, int y, float max_speed, float max_force);
        void Run(P5SDL *p5sdl);
        void Follow(Path *path, P5SDL *p5sdl, bool debug);
        void Seek(Vector target);
        void Update(void);
        void ApplyForce(Vector force);
        void Borders(Path *path);
        void Show(P5SDL *p5sdl);
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
