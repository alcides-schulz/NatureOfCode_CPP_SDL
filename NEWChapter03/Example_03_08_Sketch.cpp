#include "Example_03_08_Sketch.h"

namespace nature_of_code_chapter_03_example_08
{
    bool Sketch::Setup(void)
    {
        ClearScreen();
    
        for (int x = 0; x < Width(); x += 24) {
            auto y = amplitude_ * sin(angle_);
            DrawCircle(x, (int)(y + Height() / 2), 48, kColorGray, true);
            DrawCircle(x, (int)(y + Height() / 2), 48, kColorBlack, false);
            angle_ += angle_velocity_;
        }
    
        return true;
    }
    
}

// END
