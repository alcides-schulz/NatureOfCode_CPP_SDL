#include "Example_3_6.h"

bool Example_3_6::UserInit(void)
{
    angle_ = 0;
    angle_velocity_ = 0.05f;

    return true;
}

bool Example_3_6::UserRender(int elapsed_time)
{
    ClearScreen();

    auto amplitude = 200;

    auto x = static_cast<int>(amplitude * sin(angle_));

    Translate(WindowWidth() / 2, WindowHeight() / 2);

    DrawLine(0, 0, x, 0, kColorBlack);
    DrawCircle(x, 0, 30, kColorBlack, true);

    angle_ += angle_velocity_;

    return true;
}

// END
