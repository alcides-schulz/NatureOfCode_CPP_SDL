#include "Mover_1_10.h"

void Mover_1_10::Update(void)
{
    velocity_.Add(acceleration_);
    velocity_.Limit(top_speed_);
    location_.Add(velocity_);
}

void Mover_1_10::Show(SDL_Framework *framework)
{
    framework->DrawCircle((int)location_.x, (int)location_.y, 48, kColorGray, true);
}

void Mover_1_10::CheckEdges(SDL_Framework *framework)
{
    if (location_.x > framework->Width())
        location_.x = 0;
    else if (location_.x < 0)
        location_.x = (float)framework->Width();
    if (location_.y > framework->Height())
        location_.y = 0;
    else if (location_.y < 0)
        location_.y = (float)framework->Height();
}

// END
