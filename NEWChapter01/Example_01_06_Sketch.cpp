#include "Example_01_06_Sketch.h"

namespace nature_of_code_chapter_01_example_06
{
    bool Sketch::Draw()
    {
        ClearScreen();
    
        // Subtract center from mouse which results in a vector that points from center to mouse
        PVector mouse = PVector(MousePosition().x, MousePosition().y);
        PVector center = PVector(Width() / 2, Height() / 2);
    
        mouse.Sub(center);
    
        Translate(Width() / 2, Height() / 2);
        DrawLine(0, 0, (int)mouse.x, (int)mouse.y, kColorBlack);
    
        // Normalize the vector and draw the vector
        mouse.Normalize();
        mouse.Mult(50);
        DrawLine(0, 0, (int)mouse.x, (int)mouse.y, kColorRed);
    
        return true;
    }
    
}

// END
