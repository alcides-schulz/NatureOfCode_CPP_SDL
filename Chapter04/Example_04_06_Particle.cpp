#include "Example_04_06_Particle.h"

namespace nature_of_code_chapter_04_example_06
{
    void Particle::ApplyForce(Vector force)
    {
        auto temp = force.Copy();
        temp.Div(_mass);
        _acceleration.Add(temp);
    }

    void Particle::Update(void)
    {
        _velocity.Add(_acceleration);
        _position.Add(_velocity);
        _acceleration.Mult(0);
        _life_span = max(0, _life_span - 2);
    }

    void Particle::Show(P5SDL *p5sdl)
    {
        p5sdl->StrokeWeight(0);
        p5sdl->Fill(127, _life_span);
        p5sdl->Circle(_position.x, _position.y, 8);
    }

    void Particle::Run(P5SDL *p5sdl)
    {
        auto gravity = Vector(0.0f, 0.05f);
        ApplyForce(gravity);
        Update();
        Show(p5sdl);
    }

}

// END
