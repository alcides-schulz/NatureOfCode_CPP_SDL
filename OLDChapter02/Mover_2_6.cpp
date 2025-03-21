#include "Mover_2_6.h"

void Mover_2_6::ApplyForce(PVector force)
{
    auto temp = force.Clone();
    temp.Div((float)mass_);
    acceleration_.Add(temp);
}

void Mover_2_6::Update(void)
{
    velocity_.Add(acceleration_);
    position_.Add(velocity_);
    acceleration_.Mult(0);
}

void Mover_2_6::Show(SDL_Framework *framework)
{
    framework->DrawCircle((int)position_.x, (int)position_.y, radius_ * 2, kColorGray, true);
}

// END
