#include "Mover_1_7.h"

void Mover_1_7::Update(void)
{
    location_.Add(velocity_);
}

void Mover_1_7::Display(SDL_Framework *framework)
{
    framework->DrawCircle({ (int)location_.x, (int)location_.y }, 48, kColorGray, true);
}

void Mover_1_7::CheckEdges(SDL_Framework *framework)
{
    if (location_.x > framework->WindowWidth())
        location_.x = 0;
    else if (location_.x < 0)
        location_.x = (float)framework->WindowWidth();
    if (location_.y > framework->WindowHeight())
        location_.y = 0;
    else if (location_.y < 0)
        location_.y = (float)framework->WindowHeight();
}

// END
