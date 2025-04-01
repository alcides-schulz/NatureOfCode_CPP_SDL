#include "Example_05_12_Flock.h"

namespace nature_of_code_chapter_05_example_12
{
    void Flock::AddBoid(Boid *boid)
    {
        _boids.push_back(boid);
    }

    void Flock::Run(void)
    {
        for (auto boid : _boids)
            boid->Run();
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
