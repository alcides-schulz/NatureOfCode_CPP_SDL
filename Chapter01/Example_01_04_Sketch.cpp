#include "Example_01_04_Sketch.h"

namespace nature_of_code_chapter_01_example_04
{
    bool Sketch::Draw()
    {
        Background(255);
    
        auto mouse = PVector(MousePosition().x, MousePosition().y);
        auto center = PVector((Width() / 2), (Height() / 2));
        mouse.Sub(center);
    
        Translate(Width() / 2, Height() / 2);
        Stroke(kColorBlack);
        Line(0, 0, (int)mouse.x, (int)mouse.y);
    
        // Multiplying a vector! The vector is now half its original size (multiplied by 0.5).
        mouse.Mult(0.5);
        Stroke(kColorRed);
        Line(0, 0, (int)mouse.x, (int)mouse.y);
    
        return true;
    }
    
    
}

// END
