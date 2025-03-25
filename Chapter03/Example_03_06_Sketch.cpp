#include "Example_03_06_Sketch.h"

namespace nature_of_code_chapter_03_example_06
{
    bool Sketch::Setup(void)
    {
        angle_ = 0;
        angle_velocity_ = 0.05f;
    
        return true;
    }
    
    bool Sketch::Draw()
    {
        Background(255);
    
        auto amplitude = 200;
    
        auto x = static_cast<int>(amplitude * sin(angle_));
    
        Translate(Width() / 2, Height() / 2);
    
        Stroke(kColorBlack);
        Line(0, 0, x, 0);
        Fill(127);
        Circle(x, 0, 30);
    
        angle_ += angle_velocity_;
    
        return true;
    }
    
}

// END
