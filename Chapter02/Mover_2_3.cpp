#include "Mover_2_3.h"

void Mover_2_3::ApplyForce(PVector force)
{
    auto temp = force.Clone();
    temp.Div((float)mass_);
    acceleration_.Add(temp);
}

void Mover_2_3::Update(void)
{
    velocity_.Add(acceleration_);
    position_.Add(velocity_);
    acceleration_.Mult(0);
}

void Mover_2_3::Show(SDL_Framework *framework)
{
    framework->DrawCircle((int)position_.x, (int)position_.y, radius_ * 2, kColorGray, true);
}

void Mover_2_3::CheckEdges(SDL_Framework *framework)
{
    if (position_.x > framework->Width() - radius_) {
        position_.x = (float)framework->Width() - radius_;
        velocity_.x *= -1;
    }
    else if (position_.x < radius_) {
        position_.x = (float)radius_;
        velocity_.x *= -1;
    }
    if (position_.y > framework->Height() - radius_) {
        position_.y = (float)framework->Height() - radius_;
        velocity_.y *= -1;
    }
    else if (position_.y < radius_) {
        position_.y = (float)radius_;
        velocity_.y *= -1;
    }
}

// EOF