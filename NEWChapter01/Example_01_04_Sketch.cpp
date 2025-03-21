#include "Example_01_04_Sketch.h"

namespace nature_of_code_chapter_01_example_04
{
    bool Sketch::Draw()
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
    
    
}

// END
