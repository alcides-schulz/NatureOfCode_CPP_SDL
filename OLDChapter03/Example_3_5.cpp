#include "Example_3_5.h"

bool Example_3_5::Draw()
{
    ClearScreen();

    auto period = 120;
    auto amplitude = 200;

    auto x = static_cast<int>(amplitude * sin((M_PI * 2 * FrameCount()) / period));

    Translate(Width() / 2, Height() / 2);

    DrawLine(0, 0, x, 0, kColorBlack);
    DrawCircle(x, 0, 30, kColorBlack, true);

    return true;
}

// END
