#include "Example_03_09_Sketch.h"
#include "../Common/Utils.h"

namespace nature_of_code_chapter_03_example_09
{
    
    bool Sketch::Setup(void)
    {
        _start_angle = 0;
        _angle_velocity = 0.2f;
    
        return true;
    }
    
    bool Sketch::Draw()
    {
        Background(255);
    
        auto angle = _start_angle;
        _start_angle += 0.02f;
    
        Stroke(0);
        Fill(127, 127);
        for (int x = 0; x <= Width(); x += 24) {
            auto y = static_cast<int>(Utils::Map(sin(angle), -1, 1, 0, Height()));
            Circle(x, y, 48);
            angle += _angle_velocity;
        }
    
        return true;
    }
    
}

// END
