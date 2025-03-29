#include "Example_04_07_Repeller.h"

namespace nature_of_code_chapter_04_example_07
{
    Vector Repeller::Repel(Particle *particle)
    {
        auto force = Vector::Sub(_position, particle->GetPosition());
        auto distance = force.Mag();
        distance = std::max(5.0f, std::min(distance, 50.0f));
        auto strength = (-1 * _power) / (distance * distance);
        force.SetMag(strength);
        return force;
    }

    void Repeller::Show(P5SDL *p5sdl)
    {
        p5sdl->Stroke(0);
        p5sdl->Fill(0);
        p5sdl->Circle(_position.x, _position.y, 32);
    }
}

// END
