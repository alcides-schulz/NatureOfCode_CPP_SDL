#include "Example_1_4.h"

bool Example_1_4::Draw()
{
    ClearScreen();

    auto mouse = PVector(MousePosition().x, MousePosition().y);
    auto center = PVector((Width() / 2), (Height() / 2));
    mouse.Sub(center);

    Translate(Width() / 2, Height() / 2);
    DrawLine(0, 0, (int)mouse.x, (int)mouse.y, kColorBlack);

    // Multiplying a vector! The vector is now half its original size (multiplied by 0.5).
    mouse.Mult(0.5);
    DrawLine(0, 0, (int)mouse.x, (int)mouse.y, kColorRed);

    return true;
}

    
 //END