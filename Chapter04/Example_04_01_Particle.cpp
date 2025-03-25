#include "Example_04_01_Particle.h"

namespace nature_of_code_chapter_04_example_01
{
    void Particle::ApplyForce(PVector force)
    {
        acceleration_.Add(force);
    }
    
    void Particle::Update(void)
    {
        velocity_.Add(acceleration_);
        position_.Add(velocity_);
        acceleration_.Mult(0);
        life_span_ = std::max(0.0f, life_span_ - 2.0f);
    }
    
    void Particle::Show(SDL_Framework *framework)
    {
        framework->StrokeWeight(0);
        framework->Fill({ kColorBlack.r, kColorBlack.g, kColorBlack.b, (Uint8)life_span_ });
        framework->Circle(position_.x, position_.y, 8);
    }
}

// END
