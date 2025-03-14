#include "Example_1_2.h"

bool Example_1_2::UserInit()
{
    location_ = PVector(100, 100);
    velocity_ = PVector(2.5f, 2.0f);

    return true;
}

bool Example_1_2::UserRender(int elapsed_time)
{
    ClearScreen();

    location_.Add(velocity_);
    if (location_.x > WindowWidth() || location_.x < 0) {
        velocity_.x *= -1;
    }
    if (location_.y > WindowHeight() || location_.y < 0) {
        velocity_.y *= -1;
    }

    DrawCircle((int)location_.x, (int)location_.y, 48, kColorGray, true);

    return true;
}

// END
