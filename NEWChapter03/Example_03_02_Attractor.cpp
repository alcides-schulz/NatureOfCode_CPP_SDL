#include "Example_03_02_Attractor.h"

namespace nature_of_code_chapter_03_example_02
{
    PVector Attractor::Attract(Mover *mover)
    {
        auto force = position_.Clone();
        force.Sub(mover->GetPosition());
        auto distance = force.Mag();
        distance = (float)std::fmax(5, std::fmin(25, distance));
        auto strength = (kGravity * mass_ * mover->GetMass()) / (distance * distance);
        force.SetMag(strength);
        return force;
    }
    
    void Attractor::Show(SDL_Framework *framework)
    {
        framework->DrawCircle((int)position_.x, (int)position_.y, radius_ * 2, kColorBlack, true);
    }
    
}

// END
