#include "Example_04_08_Particle.h"

namespace nature_of_code_chapter_04_example_08
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
        _life_span = std::max(0.0f, _life_span - 2.5f);
    }

    void Particle::Show(P5SDL *p5sdl)
    {
        auto alpha = (Uint8)std::max(0.0f, _life_span);
        SDL_SetTextureAlphaMod(_texture, alpha);
        SDL_Rect image_position = { (int)_position.x - 16, (int)_position.y - 16, 32, 32 };
        SDL_RenderCopy(p5sdl->Renderer(), _texture, nullptr, &image_position);
    }

    void Particle::Run(P5SDL *p5sdl)
    {
        Update();
        Show(p5sdl);
    }

}

// END
