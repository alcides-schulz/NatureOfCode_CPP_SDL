#include "Example_04_08_Particle.h"

namespace nature_of_code_chapter_04_example_08
{
    void Particle::ApplyForce(Vector force)
    {
        acceleration_.Add(force);
    }

    void Particle::Update(void)
    {
        velocity_.Add(acceleration_);
        position_.Add(velocity_);
        acceleration_.Mult(0);
        life_span_ = std::max(0.0f, life_span_ - 2.5f);
    }

    void Particle::Show(SDL_Framework *framework)
    {
        auto alpha = (Uint8)std::max(0.0f, life_span_);
        SDL_SetTextureAlphaMod(texture_, alpha);
        SDL_Rect image_position = { (int)position_.x - 16, (int)position_.y - 16, 32, 32 };
        SDL_RenderCopy(framework->Renderer(), texture_, nullptr, &image_position);
    }

    void Particle::Run(SDL_Framework *framework)
    {
        Update();
        Show(framework);
    }

}

// END
