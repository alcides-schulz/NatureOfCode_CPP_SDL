#include "Example_02_09_Body.h"

namespace nature_of_code_chapter_02_example_09
{
    void Body::ApplyForce(Vector force)
    {
        Vector temp = force.Clone();
        temp.Div((float)_mass);
        _acceleration.Add(temp);
    }
    
    void Body::Update(void)
    {
        _velocity.Add(_acceleration);
        _position.Add(_velocity);
        _acceleration.Mult(0);
    }
    
    void Body::Show(P5SDL *p5sdl)
    {
        p5sdl->Stroke(0);
        p5sdl->Fill(127);
        p5sdl->Circle(_position.x, _position.y, _mass * 16);
    }
    
    void Body::Attract(Body *body)
    {
        auto force = Vector(_position.x, _position.y);
        force.Sub(body->GetPosition());
        auto distance = force.Mag();
        distance = (float)std::fmax(5, std::fmin(25, distance));
        auto strength = (kGravity * _mass * body->GetMass()) / (distance * distance);
        force.SetMag(strength);
        body->ApplyForce(force);
    }
    
}

// END
