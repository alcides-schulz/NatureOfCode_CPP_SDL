#include "Mover_1_10.h"

void Mover_1_10::Update(void)
{
    velocity_.Add(acceleration_);
    velocity_.Limit(top_speed_);
    position_.Add(velocity_);
}

void Mover_1_10::Show(SDL_Framework *framework)
{
    framework->DrawCircle((int)position_.x, (int)position_.y, 48, kColorGray, true);
}

void Mover_1_10::CheckEdges(SDL_Framework *framework)
{
    if (position_.x > framework->Width())
        position_.x = 0;
    else if (position_.x < 0)
        position_.x = (float)framework->Width();
    if (position_.y > framework->Height())
        position_.y = 0;
    else if (position_.y < 0)
        position_.y = (float)framework->Height();
}

// END
