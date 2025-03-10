#include "Example_1_6.h"

bool Example_1_6::UserRender(int elapsed_time)
{
    ClearScreen();

    // Subtract center from mouse which results in a vector that points from center to mouse
    PVector mouse = PVector(MousePosition().x, MousePosition().y);
    PVector center = PVector(WindowWidth() / 2, WindowHeight() / 2);

    mouse.Sub(center);

    Translate(WindowWidth() / 2, WindowHeight() / 2);
    DrawLine(0, 0, (int)mouse.x, (int)mouse.y, kColorBlack);

    // Normalize the vector and draw the vector
    mouse.Normalize();
    mouse.Mult(50);
    DrawLine(0, 0, (int)mouse.x, (int)mouse.y, kColorRed);

    return true;
}

// END
