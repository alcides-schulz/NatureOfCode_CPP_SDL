#include "Particle_4_1.h"

void Particle_4_1::ApplyForce(PVector force)
{
    acceleration_.Add(force);
}

void Particle_4_1::Update(void)
{
    velocity_.Add(acceleration_);
    position_.Add(velocity_);
    life_span_ -= 2.0f;
    acceleration_.Mult(0);
}

void Particle_4_1::Show(SDL_Framework *framework)
{
    framework->DrawCircle(position_.x, position_.y, 8, { kColorBlack.r, kColorBlack.g, kColorBlack.b, (Uint8)life_span_ }, true);
}

// END
