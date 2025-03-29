#include "Example_01_02_Sketch.h"

namespace nature_of_code_chapter_01_example_02
{
    bool Sketch::Setup()
    {
        cout << _position.x << endl;
        _position = Vector(100, 100);
        _velocity = Vector(2.5f, 2.0f);
        return true;
    }
    
    bool Sketch::Draw()
    {
        Background(255);
    
        _position.Add(_velocity);
        if (_position.x > Width() || _position.x < 0) {
            _velocity.x *= -1;
        }
        if (_position.y > Height() || _position.y < 0) {
            _velocity.y *= -1;
        }
    
        Stroke(0);
        Fill(127);
        Circle(_position.x, _position.y, 48);
    
        return true;
    }
    
}

// END
