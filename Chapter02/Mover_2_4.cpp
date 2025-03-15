#include "Mover_2_4.h"

void Mover_2_4::ApplyForce(PVector force)
{
    auto temp = force.Clone();
    temp.Div((float)mass_);
    acceleration_.Add(temp);
}

void Mover_2_4::Update(void)
{
    velocity_.Add(acceleration_);
    position_.Add(velocity_);
    acceleration_.Mult(0);
}

void Mover_2_4::Show(SDL_Framework *framework)
{
    framework->DrawCircle((int)position_.x, (int)position_.y, radius_ * 2, kColorGray, true);
}

bool Mover_2_4::ContactEdge(SDL_Framework *framework)
{
    return position_.y > framework->Height() - radius_ - 1;
}

void Mover_2_4::BounceEdges(SDL_Framework *framework)
{
    float bounce = -0.9f;
    if (position_.x > framework->Width() - radius_) {
        position_.x = (float)(framework->Width() - radius_);
        velocity_.x *= bounce;
    }
    else if (position_.x < radius_) {
        position_.x = (float)radius_;
        velocity_.x *= bounce;
    }
    if (position_.y > framework->Height() - radius_) {
        position_.y = (float)(framework->Height() - radius_);
        velocity_.y *= bounce;
    }
}

// EOF