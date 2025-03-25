#include "Example_03_08_Sketch.h"

namespace nature_of_code_chapter_03_example_08
{
    bool Sketch::Setup(void)
    {
        Background(255);
    
        for (int x = 0; x < Width(); x += 24) {
            auto y = amplitude_ * sin(angle_);
            Fill(127);
            Circle(x, (int)(y + Height() / 2), 48);
            Fill(0);
            Circle(x, (int)(y + Height() / 2), 48);
            angle_ += angle_velocity_;
        }
    
        return true;
    }
    
}

// END
