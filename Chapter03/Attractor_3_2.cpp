#include "Attractor_3_2.h"

PVector Attractor_3_2::Attract(Mover_3_2 *mover)
{
    auto force = PVector(position_.x, position_.y);
    force.Sub(mover->GetPosition());
    auto distance = force.Mag();
    distance = (float)std::fmax(5, std::fmin(25, distance));
    auto strength = (kGravity * mass_ * mover->GetMass()) / (distance * distance);
    force.SetMag(strength);
    return force;
}

void Attractor_3_2::Display(SDL_Framework *framework)
{
    framework->DrawCircle({ (int)position_.x, (int)position_.y }, radius_, { 0, 0, 255, 0 }, true);
}

// END
