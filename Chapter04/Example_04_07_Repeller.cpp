#include "Example_04_07_Repeller.h"

namespace nature_of_code_chapter_04_example_07
{
    PVector Repeller::Repel(Particle *particle)
    {
        auto force = PVector::Sub(position_, particle->GetPosition());
        auto distance = force.Mag();
        distance = std::max(5.0f, std::min(distance, 50.0f));
        auto strength = (-1 * power_) / (distance * distance);
        force.SetMag(strength);
        return force;
    }

    void Repeller::Show(SDL_Framework *framework)
    {
        framework->Stroke(0);
        framework->Fill(0);
        framework->Circle(position_.x, position_.y, 32);
    }
}

// END
