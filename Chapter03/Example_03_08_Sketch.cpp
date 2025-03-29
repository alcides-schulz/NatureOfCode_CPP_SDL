#include "Example_03_08_Sketch.h"

namespace nature_of_code_chapter_03_example_08
{
    bool Sketch::Setup(void)
    {
        Background(255);
    
        Stroke(0);
        Fill(127, 127);
        for (int x = 0; x < Width(); x += 24) {
            auto y = amplitude_ * sin(angle_);
            Circle(x, (int)(y + Height() / 2), 48);
            angle_ += angle_velocity_;
        }
    
        return true;
    }
    
}

// END
