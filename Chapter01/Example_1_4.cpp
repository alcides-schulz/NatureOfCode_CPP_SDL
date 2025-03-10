#include "Example_1_4.h"

bool Example_1_4::UserRender(int elapsed_time)
{
    ClearScreen();

    PVector mouse = PVector(MousePosition().x, MousePosition().y);
    PVector center = PVector((WindowWidth() / 2), (WindowHeight() / 2));
    mouse.Sub(center);

    Translate(WindowWidth() / 2, WindowHeight() / 2);
    DrawLine(0, 0, (int)mouse.x, (int)mouse.y, kColorBlack);

    // Multiplying a vector! The vector is now half its original size (multiplied by 0.5).
    mouse.Mult(0.5);
    DrawLine(0, 0, (int)mouse.x, (int)mouse.y, kColorRed);

    return true;
}

    
 //END