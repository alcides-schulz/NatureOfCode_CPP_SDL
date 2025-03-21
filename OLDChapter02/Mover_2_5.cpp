#include "Mover_2_5.h"

void Mover_2_5::ApplyForce(PVector force)
{
    auto temp = force.Clone();
    temp.Div((float)mass_);
    acceleration_.Add(temp);
}

void Mover_2_5::Update(void)
{
    velocity_.Add(acceleration_);
    position_.Add(velocity_);
    acceleration_.Mult(0);
}

void Mover_2_5::Show(SDL_Framework *framework)
{
    framework->DrawCircle((int)position_.x, (int)position_.y, radius_ * 2, kColorGray, true);
}

void Mover_2_5::CheckEdges(SDL_Framework *framework)
{
    if (position_.y > framework->Height() - radius_) {
        position_.y = (float)(framework->Height() - radius_);
        velocity_.y *= -0.9f;
    }
}

// END
