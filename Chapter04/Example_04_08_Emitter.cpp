#include "Example_04_08_Emitter.h"

namespace nature_of_code_chapter_04_example_08
{
    void Emitter::ApplyForce(PVector force)
    {
        for (auto particle : particles_) {
            particle->ApplyForce(force);
        }
    }

    void Emitter::AddParticle(void)
    {
        particles_.push_back(new Particle((int)origin_.x, (int)origin_.y, texture_));
    }

    void Emitter::Run(SDL_Framework *framework)
    {
        for (int i = (int)particles_.size() - 1; i >= 0; i--) {
            auto particle = particles_[i];
            particle->Run(framework);
            if (particle->IsDead())
                particles_.erase(particles_.begin() + i);
        }
    }
}

// END
