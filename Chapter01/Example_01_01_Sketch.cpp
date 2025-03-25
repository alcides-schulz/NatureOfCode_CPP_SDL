#include "Example_01_01_Sketch.h"

namespace nature_of_code_chapter_01_example_01
{
    bool Sketch::Setup()
    {
        x_ = 100;
        y_ = 100;
        x_speed_ = 2.5f;
        y_speed_ = 2.0f;
    
        return true;
    }
    
    bool Sketch::Draw()
    {
        Background(255);
    
        x_ += x_speed_;
        y_ += y_speed_;
        if (x_ > Width() || x_ < 0) {
            x_speed_ *= -1;
        }
        if (y_ > Height() || y_ < 0) {
            y_speed_ *= -1;
        }
    
        Stroke(0);
        Fill(127);
        Circle(x_, y_, 48);
    
        return true;
    }
    
}

// END
