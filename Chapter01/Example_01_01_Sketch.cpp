#include "Example_01_01_Sketch.h"

namespace nature_of_code_chapter_01_example_01
{
    bool Sketch::Setup()
    {
        _x = 100;
        _y = 100;
        _x_speed = 2.5f;
        _y_speed = 2.0f;
    
        return true;
    }
    
    bool Sketch::Draw()
    {
        Background(255);
    
        _x += _x_speed;
        _y += _y_speed;
        if (_x > Width() || _x < 0) {
            _x_speed *= -1;
        }
        if (_y > Height() || _y < 0) {
            _y_speed *= -1;
        }
    
        Stroke(0);
        Fill(127);
        Circle(_x, _y, 48);
    
        return true;
    }
    
}

// END
