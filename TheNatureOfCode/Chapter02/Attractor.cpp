#include "Attractor.h"

PVector Attractor::Attract(Chapter02MoverV1 *mover)
{
    auto force = PVector(position_.x, position_.y);
    force.Sub(mover->GetPosition());
    auto distance = force.Mag();
    distance = (float)std::fmax(3, std::fmin(15, distance));
    auto strength = (kGravity * mass_ * mover->GetMass()) / (distance * distance);
    force.Limit(strength);
    return force;
}

void Attractor::Display(SDL_Framework *framework)
{
    framework->DrawCircle({ (int)position_.x, (int)position_.y }, radius_, { 0, 0, 255, 0 }, true);
}

// END
