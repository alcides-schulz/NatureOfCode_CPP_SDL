#include "Example_1_2.h"

bool Example_1_2::UserRender(int elapsed_time)
{
    SDL_SetRenderDrawColor(Renderer(), kColorWhite.r, kColorWhite.g, kColorWhite.b, 255);
    SDL_RenderClear(Renderer());

    location_.Add(velocity_);
    if (location_.x > WindowWidth() - radius_ || location_.x < radius_) {
        velocity_.x *= -1;
    }
    if (location_.y > WindowHeight() - radius_ || location_.y < radius_) {
        velocity_.y *= -1;
    }
    DrawCircle({ (int)location_.x, (int)location_.y }, radius_, kColorGray, true);

    return true;
}

// END
