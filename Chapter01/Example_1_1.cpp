#include "Example_1_1.h"

bool Example_1_1::UserRender(int elapsed_time)
{
    SDL_SetRenderDrawColor(Renderer(), kColorWhite.r, kColorWhite.g, kColorWhite.b, 255);
    SDL_RenderClear(Renderer());

    x_ += x_speed_;
    y_ += y_speed_;
    if (x_ > WindowWidth() - radius_ || x_ < radius_) {
        x_speed_ *= -1;
    }
    if (y_ > WindowHeight() - radius_ || y_ < radius_) {
        y_speed_ *= -1;
    }
    DrawCircle({ (int)x_, (int)y_ }, radius_, kColorGray, true);

    return true;
}

// END
