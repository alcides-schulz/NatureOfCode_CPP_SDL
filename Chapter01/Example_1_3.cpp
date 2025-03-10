#include "Example_1_3.h"

bool Example_1_3::UserRender(int elapsed_time)
{
    ClearScreen();

    auto mouse = PVector(MousePosition().x, MousePosition().y);
    auto center = PVector((WindowWidth() / 2), (WindowHeight() / 2));

    DrawLine(0, 0, (int)mouse.x, (int)mouse.y, kColorBlack);
    DrawLine(0, 0, (int)center.x, (int)center.y, kColorBlack);

    mouse.Sub(center);

    // Draw a line to represent the result of subtraction.
    Translate(WindowWidth() / 2, WindowHeight() / 2);
    DrawLine(0, 0, (int)mouse.x, (int)mouse.y, kColorRed);

    return true;
}

//END