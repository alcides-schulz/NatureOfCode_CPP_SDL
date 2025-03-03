#include "Body.h"

void Body::ApplyForce(PVector force)
{
    PVector temp = PVector(force);
    temp.Div((float)mass_);
    acceleration_.Add(temp);
}

void Body::Update(void)
{
    velocity_.Add(acceleration_);
    position_.Add(velocity_);
    acceleration_.Mult(0);
}

void Body::Display(SDL_Framework *framework)
{
    framework->DrawCircle({ (int)position_.x, (int)position_.y }, radius_, { 255, 0, 0, 0 }, true);
}

void Body::CheckEdges(SDL_Framework *framework)
{
    if (position_.x > framework->WindowWidth() - radius_) {
        position_.x = (float)framework->WindowWidth() - radius_;
        velocity_.x *= -1;
    }
    if (position_.x < radius_) {
        position_.x = (float)radius_;
        velocity_.x *= -1;
    }
    if (position_.y > framework->WindowHeight() - radius_) {
        position_.y = (float)framework->WindowHeight() - radius_;
        velocity_.y *= -1;
    }
    if (position_.y < radius_) {
        position_.y = (float)radius_;
        velocity_.y *= -1;
    }
}

void Body::Attract(Body *body)
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