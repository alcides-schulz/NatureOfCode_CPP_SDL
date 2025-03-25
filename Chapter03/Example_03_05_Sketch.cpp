#include "Example_03_05_Sketch.h"

namespace nature_of_code_chapter_03_example_05
{
    bool Sketch::Draw()
    {
        Background(255);
    
        auto period = 120;
        auto amplitude = 200;
    
        auto x = static_cast<int>(amplitude * sin((M_PI * 2 * FrameCount()) / period));
    
        Translate(Width() / 2, Height() / 2);
    
        Stroke(kColorBlack);
        Line(0, 0, x, 0);
        Fill(127);
        Circle(x, 0, 30);
    
        return true;
    }
    
}

// END
