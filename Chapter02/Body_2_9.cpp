#include "Body_2_9.h"

void Body_2_9::ApplyForce(PVector force)
{
    PVector temp = force.Clone();
    temp.Div((float)mass_);
    acceleration_.Add(temp);
}

void Body_2_9::Update(void)
{
    velocity_.Add(acceleration_);
    position_.Add(velocity_);
    acceleration_.Mult(0);
}

void Body_2_9::Display(SDL_Framework *framework)
{
    framework->DrawCircle({ (int)position_.x, (int)position_.y }, mass_ * 16, kColorGray, true);
}

void Body_2_9::Attract(Body_2_9 *body)
{
    auto force = PVector(position_.x, position_.y);
    force.Sub(body->GetPosition());
    auto distance = force.Mag();
    distance = (float)std::fmax(5, std::fmin(25, distance));
    auto strength = (kGravity * mass_ * body->GetMass()) / (distance * distance);
    force.SetMag(strength);
    body->ApplyForce(force);
}

// EOF