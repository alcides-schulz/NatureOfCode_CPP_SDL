#include "Example_01_02_Sketch.h"

namespace nature_of_code_chapter_01_example_02
{
    bool Sketch::Setup()
    {
        cout << position_.x << endl;
        position_ = Vector(100, 100);
        velocity_ = Vector(2.5f, 2.0f);
        return true;
    }
    
    bool Sketch::Draw()
    {
        Background(255);
    
        position_.Add(velocity_);
        if (position_.x > Width() || position_.x < 0) {
            velocity_.x *= -1;
        }
        if (position_.y > Height() || position_.y < 0) {
            velocity_.y *= -1;
        }
    
        Stroke(0);
        Fill(127);
        Circle(position_.x, position_.y, 48);
    
        return true;
    }
    
}

// END
