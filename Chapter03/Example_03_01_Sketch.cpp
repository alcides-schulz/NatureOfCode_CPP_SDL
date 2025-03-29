#include "Example_03_01_Sketch.h"

namespace nature_of_code_chapter_03_example_01
{
    bool Sketch::Setup(void)
    {
        _angle = 0;
        _angle_velocity = 0;
        _angle_acceleration = 0.0001f;
    
        return true;
    }
    
    bool Sketch::Draw()
    {
        Background(255);
    
        int line_x1 = -60;
        int line_y1 = 0;
        int line_x2 = 60;
        int line_y2 = 0;
    
        Translate(Width() / 2, Height() / 2);
        Rotate(_angle);
        Stroke(kColorBlack);
        Line(line_x1, line_y1, line_x2, line_y2);
        Fill(127);
        Circle(line_x1, line_y1, 16);
        Circle(line_x2, line_y2, 16);
    
        _angle_velocity += _angle_acceleration;
        _angle += _angle_velocity;
    
        return true;
    }
    
}

// END
