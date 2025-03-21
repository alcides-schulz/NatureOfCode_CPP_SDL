#include "Example_4_2.h"

bool Example_4_2::Setup(void)
{
    return true;
}

bool Example_4_2::Draw(void)
{
    ClearScreen();

    particles_.push_back(new Particle_4_2(Width() / 2, 20));

    for (int i = (int)particles_.size() - 1; i >= 0; i--) {
        auto particle = particles_[i];
        particle->Run(this);
        if (particle->IsDead())
            particles_.erase(particles_.begin() + i);
    }

    return true;
}

// END
