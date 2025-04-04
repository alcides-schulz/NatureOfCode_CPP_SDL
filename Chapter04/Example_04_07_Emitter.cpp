#include "Example_04_07_Emitter.h"

namespace nature_of_code_chapter_04_example_07
{
    void Emitter::AddParticle(void)
    {
        _particles.push_back(new Particle((int)_origin.x, (int)_origin.y));
    }

    void Emitter::Run(P5SDL *p5sdl)
    {
        for (int i = (int)_particles.size() - 1; i >= 0; i--) {
            auto particle = _particles[i];
            particle->Run(p5sdl);
            if (particle->IsDead()) {
                _particles.erase(_particles.begin() + i);
                delete particle;
            }
        }
    }

    void Emitter::ApplyRepeller(Repeller *repeller)
    {
        for (auto particle : _particles) {
            auto force = repeller->Repel(particle);
            particle->ApplyForce(force);
        }
    }

    void Emitter::ApplyForce(Vector force)
    {
        for (auto particle : _particles) {
            particle->ApplyForce(force);
        }
    }
}

// END
