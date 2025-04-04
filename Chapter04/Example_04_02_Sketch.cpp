#include "Example_04_02_Sketch.h"

namespace nature_of_code_chapter_04_example_02
{
    bool Sketch::Setup(void)
    {
        return true;
    }
    
    bool Sketch::Draw(void)
    {
        Background(255);
    
        _particles.push_back(new Particle(Width() / 2, 20));
    
        for (int i = (int)_particles.size() - 1; i >= 0; i--) {
            auto particle = _particles[i];
            particle->Run(this);
            if (particle->IsDead()) {
                _particles.erase(_particles.begin() + i);
                delete particle;
            }
        }
    
        return true;
    }
    
}

// END
