#include "Example_04_02_Sketch.h"

namespace nature_of_code_chapter_04_example_02
{
    bool Sketch::Setup(void)
    {
        return true;
    }
    
    bool Sketch::Draw(void)
    {
        ClearScreen();
    
        particles_.push_back(new Particle(Width() / 2, 20));
    
        for (int i = (int)particles_.size() - 1; i >= 0; i--) {
            auto particle = particles_[i];
            particle->Run(this);
            if (particle->IsDead())
                particles_.erase(particles_.begin() + i);
        }
    
        return true;
    }
    
}

// END
