#include "Example_3_8.h"

bool Example_3_8::Setup(void)
{
    ClearScreen();

    for (int x = 0; x < Width(); x += 24) {
        auto y = amplitude_ * sin(angle_);
        DrawCircle(x, (int)(y + Height() / 2), 48, kColorGray, true);
        DrawCircle(x, (int)(y + Height() / 2), 48, kColorBlack, false);
        angle_ += angle_velocity_;
    }

    return true;
}

// END
