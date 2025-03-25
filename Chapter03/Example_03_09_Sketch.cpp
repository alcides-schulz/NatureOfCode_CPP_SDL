#include "Example_03_09_Sketch.h"
#include "../Common/Utils.h"
namespace nature_of_code_chapter_03_example_09
{
    
    bool Sketch::Setup(void)
    {
        start_angle_ = 0;
        angle_velocity_ = 0.2f;
    
        return true;
    }
    
    bool Sketch::Draw()
    {
        Background(255);
    
        auto angle = start_angle_;
        start_angle_ += 0.02f;
    
        for (int x = 0; x <= Width(); x += 24) {
            auto y = static_cast<int>(Utils::Map(sin(angle), -1, 1, 0, Height()));
            Fill(127);
            Circle(x, y, 48);
            Fill(0);
            Circle(x, y, 48);
            angle += angle_velocity_;
        }
    
        return true;
    }
    
}

// END
