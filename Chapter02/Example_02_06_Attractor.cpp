#include "Example_02_06_Attractor.h"

namespace nature_of_code_chapter_02_example_06
{
    Vector Attractor::Attract(Mover *mover)
    {
        auto force = Vector(_position.x, _position.y);
        force.Sub(mover->GetPosition());
        auto distance = force.Mag();
        distance = (float)std::fmax(5, std::fmin(25, distance));
        auto strength = (kGravity * _mass * mover->GetMass()) / (distance * distance);
        force.SetMag(strength);
        return force;
    }
    
    void Attractor::Show(P5SDL *p5sdl)
    {
        p5sdl->Stroke(0);
        p5sdl->Fill(0);
        p5sdl->Circle(_position.x, _position.y, _mass * 2);
    }
    
}

// END
