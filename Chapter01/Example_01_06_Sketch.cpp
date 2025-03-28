#include "Example_01_06_Sketch.h"

namespace nature_of_code_chapter_01_example_06
{
    bool Sketch::Draw()
    {
        Background(255);
    
        // Subtract center from mouse which results in a vector that points from center to mouse
        Vector mouse = Vector(MousePosition().x, MousePosition().y);
        Vector center = Vector(Width() / 2, Height() / 2);
    
        mouse.Sub(center);
    
        Translate(Width() / 2, Height() / 2);
        Stroke(kColorBlack);
        Line(0, 0, (int)mouse.x, (int)mouse.y);
    
        // Normalize the vector and draw the vector
        mouse.Normalize();
        mouse.Mult(50);
        Stroke(kColorRed);
        Line(0, 0, (int)mouse.x, (int)mouse.y);
    
        return true;
    }
    
}

// END
