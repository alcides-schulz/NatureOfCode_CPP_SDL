#include "Mover_3_3.h"

void Mover_3_3::Update(SDL_Framework *framework)
{
    auto direction = PVector(framework->MousePosition().x, framework->MousePosition().y);
    direction.Sub(position_);
    direction.Normalize();
    direction.Mult(0.5f);

    acceleration_ = direction;

    velocity_.Add(acceleration_);
    velocity_.Limit(top_speed_);
    position_.Add(velocity_);
}

void Mover_3_3::Display(SDL_Framework *framework)
{
    auto angle = velocity_.Heading();
    framework->Translate(static_cast<int>(position_.x), static_cast<int>(position_.y));
    framework->RotateRadians(angle);
    framework->DrawRectangle(0, 0, 40, 20, kColorBlack);
}

void Mover_3_3::CheckEdges(SDL_Framework *framework)
{
    if (position_.x > framework->WindowWidth())
        position_.x = 0;
    else if (position_.x < 0)
        position_.x = static_cast<float>(framework->WindowWidth());
    if (position_.y > framework->WindowHeight())
        position_.y = 0;
    else if (position_.y < 0)
        position_.y = static_cast<float>(framework->WindowHeight());
}

// EOF