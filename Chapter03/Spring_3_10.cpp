#include "Spring_3_10.h"

void Spring_3_10::Connect(Bob_3_10 *bob)
{
    auto force = PVector::Sub(bob->GetPosition(), anchor_);
    float current_length = force.Mag();
    float stretch = current_length - rest_length_;
    force.SetMag(-1 * k_ * stretch);
    bob->ApplyForce(force);
}

void Spring_3_10::ConstrainLength(Bob_3_10 *bob, float min_length, float max_length)
{
    auto direction = PVector::Sub(bob->GetPosition(), anchor_);
    float length = direction.Mag();
    if (length < min_length) {
        direction.SetMag(min_length);
        bob->SetPosition(PVector::Add(anchor_, direction));
        bob->SetVelocity(PVector(0, 0));
    }
    else if (length > max_length) {
        direction.SetMag(max_length);
        bob->SetPosition(PVector::Add(anchor_, direction));
        bob->SetVelocity(PVector(0, 0));
    }
}

void Spring_3_10::Display(SDL_Framework *framework)
{
    framework->DrawCircle(anchor_.x, anchor_.y, 10, kColorBlack, true);
}

void Spring_3_10::ShowLine(SDL_Framework *framework, Bob_3_10 *bob)
{
    framework->DrawLine(bob->GetPosition().x, bob->GetPosition().y, anchor_.x, anchor_.y, kColorBlack);
}

// EOF