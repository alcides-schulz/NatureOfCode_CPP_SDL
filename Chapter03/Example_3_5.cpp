#include "Example_3_5.h"

bool Example_3_5::UserRender(int elapsed_time)
{
    ClearScreen();

    auto period = 120;
    auto amplitude = 200;

    auto x = static_cast<int>(amplitude * sin((M_PI * 2 * FrameCount()) / period));

    Translate(WindowWidth() / 2, WindowHeight() / 2);

    DrawLine(0, 0, x, 0, kColorBlack);
    DrawCircle(x, 0, 30, kColorBlack, true);

    return true;
}

// END
