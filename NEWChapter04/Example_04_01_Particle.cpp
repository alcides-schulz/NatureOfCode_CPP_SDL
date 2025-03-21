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
        life_span_ -= 2.0f;
        acceleration_.Mult(0);
    }
    
    void Particle::Show(SDL_Framework *framework)
    {
        SDL_Color color = kColorBlack;
        auto alpha = (Uint8)std::max(0.0f, life_span_);
        framework->DrawCircle(position_.x, position_.y, 8, { color.r, color.g, color.b, alpha }, true);
    }
    
}

// END
