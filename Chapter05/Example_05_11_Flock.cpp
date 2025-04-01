#include "Example_05_11_Flock.h"

namespace nature_of_code_chapter_05_example_11
{
    void Flock::AddBoid(Boid *boid)
    {
        _boids.push_back(boid);
    }

    void Flock::Run(void)
    {
        for (auto boid : _boids)
            boid->Run(_boids);
    }

    void Flock::Cleanup(void)
    {
        while (!_boids.empty()) {
            delete _boids.back();
            _boids.pop_back();
        }
    }
}

// END
