#include "Chapter01MoverV1.h"

void Chapter01MoverV1::Update(void) 
{
    velocity_.Add(acceleration_);
    velocity_.Limit(top_speed_);
    location_.Add(velocity_);
}

void Chapter01MoverV1::Display(SDL_Framework *framework)
{
    framework->DrawCircle({ (int)location_.x, (int)location_.y }, radius_, { 255, 0, 0, 0 }, true);
}

void Chapter01MoverV1::CheckEdges(SDL_Framework *framework)
{
    if (location_.x > framework->WindowWidth())
        location_.x = 0;
    if (location_.x < 0)
        location_.x = (float)framework->WindowWidth();
    if (location_.y > framework->WindowHeight())
        location_.y = 0;
    if (location_.y < 0)
        location_.y = (float)framework->WindowHeight();
}

// END
