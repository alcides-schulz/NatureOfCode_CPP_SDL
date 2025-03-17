#include "Particle_4_2.h"

void Particle_4_2::ApplyForce(PVector force)
{
    acceleration_.Add(force);
}

void Particle_4_2::Update(void)
{
    velocity_.Add(acceleration_);
    position_.Add(velocity_);
    life_span_ -= 2.0f;
    acceleration_.Mult(0);
}

void Particle_4_2::Show(SDL_Framework *framework)
{
    framework->DrawCircle(position_.x, position_.y, 8, { kColorBlack.r, kColorBlack.g, kColorBlack.b, (Uint8)life_span_ }, true);
}

void Particle_4_2::Run(SDL_Framework *framework)
{
    auto gravity = PVector(0.0f, 0.05f);
    ApplyForce(gravity);
    Update();
    Show(framework);
}

// END
