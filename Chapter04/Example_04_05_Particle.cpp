#include "Example_04_05_Particle.h"

namespace nature_of_code_chapter_04_example_05
{
    void Particle::ApplyForce(Vector force)
    {
        _acceleration.Add(force);
    }

    void Particle::Update(void)
    {
        _velocity.Add(_acceleration);
        _position.Add(_velocity);
        _acceleration.Mult(0);
        _life_span = std::max(0.0f, _life_span - 2.0f);
    }

    void Particle::Show(P5SDL *p5sdl)
    {
        p5sdl->StrokeWeight(0);
        p5sdl->Fill({ kColorBlack.r, kColorBlack.g, kColorBlack.b, (Uint8)_life_span });
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
