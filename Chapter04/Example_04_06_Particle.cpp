#include "Example_04_06_Particle.h"

namespace nature_of_code_chapter_04_example_06
{
    void Particle::ApplyForce(PVector force)
    {
        auto temp = force.Clone();
        temp.Div(mass_);
        acceleration_.Add(temp);
    }

    void Particle::Update(void)
    {
        velocity_.Add(acceleration_);
        position_.Add(velocity_);
        life_span_ -= 2.0f;
        acceleration_.Mult(0);
    }

    void Particle::Show(SDL_Framework *framework)
    {
        SDL_Color color = kColorBlack;
        auto alpha = (Uint8)std::max(0.0f, life_span_);
        framework->DrawCircle(position_.x, position_.y, 8, { color.r, color.g, color.b, alpha }, true);
    }

    void Particle::Run(SDL_Framework *framework)
    {
        auto gravity = PVector(0.0f, 0.05f);
        ApplyForce(gravity);
        Update();
        Show(framework);
    }

}

// END
