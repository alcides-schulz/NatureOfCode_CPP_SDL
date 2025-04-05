#include "Example_02_07_Mover.h"

namespace nature_of_code_chapter_02_example_07
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
    
}

// END
