#include "Example_01_02_Sketch.h"

namespace nature_of_code_chapter_01_example_02
{
    bool Sketch::Setup()
    {
        position_ = PVector(100, 100);
        velocity_ = PVector(2.5f, 2.0f);
    
        return true;
    }
    
    bool Sketch::Draw()
    {
        ClearScreen();
    
        position_.Add(velocity_);
        if (position_.x > Width() || position_.x < 0) {
            velocity_.x *= -1;
        }
        if (position_.y > Height() || position_.y < 0) {
            velocity_.y *= -1;
        }
    
        DrawCircle(position_.x, position_.y, 48, kColorGray, true);
    
        return true;
    }
    
}

// END
