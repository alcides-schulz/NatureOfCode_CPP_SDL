#include "Example_04_01_Particle.h"

namespace nature_of_code_chapter_04_example_01
{
    void Particle::ApplyForce(Vector force)
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
    
    void Particle::Show(P5SDL *p5sdl)
    {
        p5sdl->StrokeWeight(0);
        p5sdl->Fill({ kColorBlack.r, kColorBlack.g, kColorBlack.b, (Uint8)life_span_ });
        p5sdl->Circle(position_.x, position_.y, 8);
    }
}

// END
