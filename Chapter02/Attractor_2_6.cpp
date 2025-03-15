#include "Attractor_2_6.h"

PVector Attractor_2_6::Attract(Mover_2_6 *mover)
{
    auto force = PVector(position_.x, position_.y);
    force.Sub(mover->GetPosition());
    auto distance = force.Mag();
    distance = (float)std::fmax(5, std::fmin(25, distance));
    auto strength = (kGravity * mass_ * mover->GetMass()) / (distance * distance);
    force.SetMag(strength);
    return force;
}

void Attractor_2_6::Show(SDL_Framework *framework)
{
    framework->DrawCircle((int)position_.x, (int)position_.y, mass_ * 2, kColorBlack, true);
}

// END
