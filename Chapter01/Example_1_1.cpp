#include "Example_1_1.h"

bool Example_1_1::UserInit()
{
    x_ = 100;
    y_ = 100;
    x_speed_ = 1;
    y_speed_ = 3.3f;

    return true;
}

bool Example_1_1::UserRender(int elapsed_time)
{
    ClearScreen();

    x_ += x_speed_;
    y_ += y_speed_;
    if (x_ > WindowWidth() || x_ < 0) {
        x_speed_ *= -1;
    }
    if (y_ > WindowHeight() || y_ < 0) {
        y_speed_ *= -1;
    }

    DrawCircle({ (int)x_, (int)y_ }, 48, kColorGray, true);

    return true;
}

// END
