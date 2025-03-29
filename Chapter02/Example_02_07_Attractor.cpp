#include "Example_02_07_Attractor.h"

namespace nature_of_code_chapter_02_example_07
{
    Vector Attractor::Attract(Mover *mover)
    {
        auto force = Vector(position_.x, position_.y);
        force.Sub(mover->GetPosition());
        auto distance = force.Mag();
        distance = (float)std::fmax(5, std::fmin(25, distance));
        auto strength = (kGravity * mass_ * mover->GetMass()) / (distance * distance);
        force.SetMag(strength);
        return force;
    }
    
    void Attractor::Show(P5SDL *p5sdl)
    {
        p5sdl->Stroke(0);
        p5sdl->Fill(0);
        p5sdl->Circle(position_.x, position_.y, mass_ * 2);
    }
    
}

// END
