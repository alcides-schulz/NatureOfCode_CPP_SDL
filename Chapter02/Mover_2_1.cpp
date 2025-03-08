#include "Mover_2_1.h"

void Mover_2_1::ApplyForce(PVector force)
{
    auto temp = force.Clone();
    temp.Div((float)mass_);
    acceleration_.Add(temp);
}

void Mover_2_1::Update(void)
{
    velocity_.Add(acceleration_);
    position_.Add(velocity_);
    acceleration_.Mult(0);
}

void Mover_2_1::Display(SDL_Framework *framework)
{
    framework->DrawCircle({ (int)position_.x, (int)position_.y }, radius_, kColorGray, true);
}

void Mover_2_1::CheckEdges(SDL_Framework *framework)
{
    if (position_.x > framework->WindowWidth() - radius_) {
        position_.x = (float)framework->WindowWidth() - radius_;
        velocity_.x *= -1;
    }
    else if (position_.x < radius_) {
        position_.x = (float)radius_;
        velocity_.x *= -1;
    }
    if (position_.y > framework->WindowHeight() - radius_) {
        position_.y = (float)framework->WindowHeight() - radius_;
        velocity_.y *= -1;
    }
    else if (position_.y < radius_) {
        position_.y = (float)radius_;
        velocity_.y *= -1;
    }
}

// EOF