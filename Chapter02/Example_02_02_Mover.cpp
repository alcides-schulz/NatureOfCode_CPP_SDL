#include "Example_02_02_Mover.h"

namespace nature_of_code_chapter_02_example_02
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
        p5sdl->Circle(_position.x, _position.y, _mass * 16);
    }
    
    void Mover::CheckEdges(P5SDL *p5sdl)
    {
        if (_position.x > p5sdl->Width()) {
            _position.x = (float)p5sdl->Width();
            _velocity.x *= -1;
        }
        else if (_position.x < 0) {
            _position.x = 0;
            _velocity.x *= -1;
        }
        if (_position.y > p5sdl->Height()) {
            _position.y = (float)p5sdl->Height();
            _velocity.y *= -1;
        }
        else if (_position.y < 0) {
            _position.y = 0;
            _velocity.y *= -1;
        }
    }
    
}

// END
