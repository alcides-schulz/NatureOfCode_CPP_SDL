#ifndef EXAMPLE_05_08_VEHICLE_H
#define EXAMPLE_05_08_VEHICLE_H

#include "../Common/SDL_Framework.h"
#include "../Common/Vector.h"
#include "../Common/Utils.h"
#include "Example_05_08_Path.h"

namespace nature_of_code_chapter_05_example_08
{
    class Vehicle
    {
    public:
        Vehicle(int x, int y, float max_speed, float max_force);
        void Run(SDL_Framework *framework);
        void Follow(Path *path, SDL_Framework *framework, bool debug);
        void Seek(Vector target);
        void Update(void);
        void ApplyForce(Vector force);
        void Borders(Path *path);
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
