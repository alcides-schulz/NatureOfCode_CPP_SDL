#include "Example_02_04_Mover.h"

namespace nature_of_code_chapter_02_example_04
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
    
    bool Mover::ContactEdge(P5SDL *p5sdl)
    {
        return _position.y > p5sdl->Height() - _radius - 1;
    }
    
    void Mover::BounceEdges(P5SDL *p5sdl)
    {
        float bounce = -0.9f;
        if (_position.x > p5sdl->Width() - _radius) {
            _position.x = (float)(p5sdl->Width() - _radius);
            _velocity.x *= bounce;
        }
        else if (_position.x < _radius) {
            _position.x = (float)_radius;
            _velocity.x *= bounce;
        }
        if (_position.y > p5sdl->Height() - _radius) {
            _position.y = (float)(p5sdl->Height() - _radius);
            _velocity.y *= bounce;
        }
    }
    
}

// END
