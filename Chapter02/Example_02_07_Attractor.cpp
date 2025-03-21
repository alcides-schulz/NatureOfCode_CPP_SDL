#include "Example_02_07_Attractor.h"

namespace nature_of_code_chapter_02_example_07
{
    PVector Attractor::Attract(Mover *mover)
    {
        auto force = PVector(position_.x, position_.y);
        force.Sub(mover->GetPosition());
        auto distance = force.Mag();
        distance = (float)std::fmax(5, std::fmin(25, distance));
        auto strength = (kGravity * mass_ * mover->GetMass()) / (distance * distance);
        force.SetMag(strength);
        return force;
    }
    
    void Attractor::Show(SDL_Framework *framework)
    {
        framework->DrawCircle((int)position_.x, (int)position_.y, mass_ * 2, kColorBlack, true);
    }
    
}

// END
