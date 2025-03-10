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
    framework->DrawCircle({ (int)position_.x, (int)position_.y }, 48, kColorGray, true);
}

void Mover_2_1::CheckEdges(SDL_Framework *framework)
{
    if (position_.x > framework->WindowWidth()) {
        position_.x = (float)framework->WindowWidth();
        velocity_.x *= -1;
    }
    else if (position_.x < 0) {
        position_.x = 0;
        velocity_.x *= -1;
    }
    if (position_.y > framework->WindowHeight()) {
        position_.y = (float)framework->WindowHeight();
        velocity_.y *= -1;
    }
    else if (position_.y < 0) {
        position_.y = 0;
        velocity_.y *= -1;
    }
}

// EOF