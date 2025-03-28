#include "Example_01_03_Sketch.h"

namespace nature_of_code_chapter_01_example_03
{
    bool Sketch::Draw()
    {
        Background(255);
    
        auto mouse = Vector(MousePosition().x, MousePosition().y);
        auto center = Vector((Width() / 2), (Height() / 2));
    
        Stroke(kColorBlack);
        Line(0, 0, (int)mouse.x, (int)mouse.y);
        Line(0, 0, (int)center.x, (int)center.y);
    
        mouse.Sub(center);
    
        // Draw a line to represent the result of subtraction.
        Translate(Width() / 2, Height() / 2);
        Stroke(kColorRed);
        Line(0, 0, (int)mouse.x, (int)mouse.y);
    
        return true;
    }
    
}

// END
