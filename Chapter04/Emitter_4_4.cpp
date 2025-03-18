#include "Emitter_4_4.h"

void Emitter_4_4::AddParticle(void)
{
    particles_.push_back(new Particle_4_4((int)origin_.x, (int)origin_.y));
}

void Emitter_4_4::Run(SDL_Framework *framework)
{
    for (int i = (int)particles_.size() - 1; i >= 0; i--) {
        auto particle = particles_[i];
        particle->Run(framework);
        if (particle->IsDead())
            particles_.erase(particles_.begin() + i);
    }
}

// END
