#include "Example_1_1.h"

bool Example_1_1::Setup()
{
    x_ = 100;
    y_ = 100;
    x_speed_ = 2.5f;
    y_speed_ = 2.0f;

    return true;
}

bool Example_1_1::Draw()
{
    ClearScreen();

    x_ += x_speed_;
    y_ += y_speed_;
    if (x_ > Width() || x_ < 0) {
        x_speed_ *= -1;
    }
    if (y_ > Height() || y_ < 0) {
        y_speed_ *= -1;
    }

    DrawCircle(x_, y_, 48, kColorGray, true);

    return true;
}

// END
