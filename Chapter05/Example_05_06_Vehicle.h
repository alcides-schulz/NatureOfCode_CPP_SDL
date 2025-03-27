#ifndef EXAMPLE_05_06_VEHICLE_H
#define EXAMPLE_05_06_VEHICLE_H

#include "../Common/SDL_Framework.h"
#include "../Common/PVector.h"
#include "../Common/Utils.h"
#include "Example_05_06_Path.h"

namespace nature_of_code_chapter_05_example_06
{
    class Vehicle
    {
    public:
        Vehicle(int x, int y, float max_speed, float max_force);
        void Run(SDL_Framework *framework);
        void Follow(Path *path, SDL_Framework *framework, bool debug);
        void Seek(PVector target);
        void Update(void);
        void ApplyForce(PVector force);
        void Borders(Path *path);
        void Show(SDL_Framework *framework);
    private:
        PVector position_;
        PVector velocity_;
        PVector acceleration_;
        int     r_;
        float   max_speed_;
        float   max_force_;
    };
}

#endif
