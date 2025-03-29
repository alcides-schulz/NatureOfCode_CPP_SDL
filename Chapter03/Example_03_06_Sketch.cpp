#include "Example_03_06_Sketch.h"

namespace nature_of_code_chapter_03_example_06
{
    bool Sketch::Setup(void)
    {
        _angle = 0;
        _angle_velocity = 0.05f;
    
        return true;
    }
    
    bool Sketch::Draw()
    {
        Background(255);
    
        auto amplitude = 200;
    
        auto x = static_cast<int>(amplitude * sin(_angle));
    
        Translate(Width() / 2, Height() / 2);
    
        Stroke(kColorBlack);
        Line(0, 0, x, 0);
        Fill(127);
        Circle(x, 0, 30);
    
        _angle += _angle_velocity;
    
        return true;
    }
    
}

// END
