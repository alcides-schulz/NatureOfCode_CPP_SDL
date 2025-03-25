#include "Example_03_04_Sketch.h"

namespace nature_of_code_chapter_03_example_04
{
    bool Sketch::Setup(void)
    {
        radius = Height() * 0.45f;
        theta = 0;
    
        return true;
    }
    
    bool Sketch::Draw()
    {
        Background(255);
    
        Translate(Width() / 2, Height() / 2);
    
        auto x = static_cast<int>(radius * std::cos(theta));
        auto y = static_cast<int>(radius * std::sin(theta));
    
        Stroke(kColorBlack);
        Line(0, 0, x, y);
        Fill(127);
        Circle(x, y, 30);
    
        theta += 0.02f;
    
        return true;
    }
    
}

// END
