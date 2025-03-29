#include "Example_04_08_Sketch.h"

namespace nature_of_code_chapter_04_example_08
{
    bool Sketch::Setup(void)
    {
        SDL_Surface* surface = IMG_Load(".\\Chapter04\\Example_04_08_Texture.png");
        if (!surface) {
            std::cerr << "Image could not be loaded! SDL_Error: " << IMG_GetError() << std::endl;
            return false;
        }
        _texture = SDL_CreateTextureFromSurface(Renderer(), surface);
        SDL_FreeSurface(surface);
        if (!_texture) {
            std::cerr << "Texture could not be created! SDL_Error: " << SDL_GetError() << std::endl;
            return false;
        }
        SDL_SetTextureBlendMode(_texture, SDL_BLENDMODE_BLEND); // setup for alpha blending in Particle.Show

        _emitter = new Emitter(Width() / 2, Height() - 75, _texture);

        return true;
    }

    bool Sketch::Draw(void)
    {
        Background(kColorBlack);

        auto dx = (float)Utils::Map(MousePosition().x, 0, Width(), -0.2, 0.2);
        auto wind = Vector(dx, 0.0f);
        _emitter->ApplyForce(wind);
        _emitter->Run(this);

        for (int i = 0; i < 3; i++) {
            _emitter->AddParticle();
        }

        // Draw arrow to indicate wind direction/force
        auto scayl = 500;
        auto arrow_position = Vector(Width() / 2, 50);
        auto arrow_size = 4;
        Translate(arrow_position.x, arrow_position.y);
        Rotate(wind.Heading());
        auto length = (int)(wind.Mag() * scayl);
        Stroke(kColorWhite);
        Line(0, 0, length, 0);
        Line(length, 0, length - arrow_size, +arrow_size / 2);
        Line(length, 0, length - arrow_size, -arrow_size / 2);

        return true;
    }

    void Sketch::Cleanup(void)
    {
        SDL_DestroyTexture(_texture);
    }
}

// END
