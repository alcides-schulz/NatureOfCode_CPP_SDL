#include "Example_01_03_Sketch.h"

namespace nature_of_code_chapter_01_example_03
{
    bool Sketch::Draw()
    {
        ClearScreen();
    
        auto mouse = PVector(MousePosition().x, MousePosition().y);
        auto center = PVector((Width() / 2), (Height() / 2));
    
        DrawLine(0, 0, (int)mouse.x, (int)mouse.y, kColorBlack);
        DrawLine(0, 0, (int)center.x, (int)center.y, kColorBlack);
    
        mouse.Sub(center);
    
        // Draw a line to represent the result of subtraction.
        Translate(Width() / 2, Height() / 2);
        DrawLine(0, 0, (int)mouse.x, (int)mouse.y, kColorRed);
    
        return true;
    }
    
}

// END
