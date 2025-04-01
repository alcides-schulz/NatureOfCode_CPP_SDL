#ifndef EXAMPLE_05_12_FLOCK_H
#define EXAMPLE_05_12_FLOCK_H

#include "../Common/P5SDL.h"
#include "../Common/Vector.h"
#include "../Common/Utils.h"
#include "Example_05_12_Boid.h"

namespace nature_of_code_chapter_05_example_12
{
    class Flock
    {
    public:
        Flock(void) {};
        void AddBoid(Boid *boid);
        void Run(void);
        void Cleanup(void);
        vector<Boid *> GetBoids(void) { return _boids; };
    private:
        vector<Boid *> _boids;
    };
}

#endif
