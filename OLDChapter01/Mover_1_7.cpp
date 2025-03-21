#include "Mover_1_7.h"

void Mover_1_7::Update(void)
{
    position_.Add(velocity_);
}

void Mover_1_7::Show(SDL_Framework *framework)
{
    framework->DrawCircle((int)position_.x, (int)position_.y, 48, kColorGray, true);
}

void Mover_1_7::CheckEdges(SDL_Framework *framework)
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
