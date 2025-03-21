#include "Example_3_6.h"

bool Example_3_6::Setup(void)
{
    angle_ = 0;
    angle_velocity_ = 0.05f;

    return true;
}

bool Example_3_6::Draw()
{
    ClearScreen();

    auto amplitude = 200;

    auto x = static_cast<int>(amplitude * sin(angle_));

    Translate(Width() / 2, Height() / 2);

    DrawLine(0, 0, x, 0, kColorBlack);
    DrawCircle(x, 0, 30, kColorBlack, true);

    angle_ += angle_velocity_;

    return true;
}

// END
