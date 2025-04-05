#include "Example_02_05_Mover.h"

namespace nature_of_code_chapter_02_example_05
{
    void Mover::ApplyForce(Vector force)
    {
        auto temp = force.Copy();
        temp.Div((float)_mass);
        _acceleration.Add(temp);
    }
    
    void Mover::Update(void)
    {
        _velocity.Add(_acceleration);
        _position.Add(_velocity);
        _acceleration.Mult(0);
    }
    
    void Mover::Show(P5SDL *p5sdl)
    {
        p5sdl->Stroke(0);
        p5sdl->Fill(127);
        p5sdl->Circle(_position.x, _position.y, _radius * 2);
    }
    
    void Mover::CheckEdges(P5SDL *p5sdl)
    {
        if (_position.y > p5sdl->Height() - _radius) {
            _position.y = (float)(p5sdl->Height() - _radius);
            _velocity.y *= -0.9f;
        }
    }
    
}

// END
