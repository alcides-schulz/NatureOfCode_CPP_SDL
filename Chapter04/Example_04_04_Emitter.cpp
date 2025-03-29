#include "Example_04_04_Emitter.h"

namespace nature_of_code_chapter_04_example_04
{
    void Emitter::AddParticle(void)
    {
        particles_.push_back(new Particle((int)origin_.x, (int)origin_.y));
    }
    
    void Emitter::Run(P5SDL *p5sdl)
    {
        for (int i = (int)particles_.size() - 1; i >= 0; i--) {
            auto particle = particles_[i];
            particle->Run(p5sdl);
            if (particle->IsDead())
                particles_.erase(particles_.begin() + i);
        }
    }
    
}

// END
