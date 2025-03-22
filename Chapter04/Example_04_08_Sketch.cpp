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
        texture_ = SDL_CreateTextureFromSurface(Renderer(), surface);
        SDL_FreeSurface(surface);
        if (!texture_) {
            std::cerr << "Texture could not be created! SDL_Error: " << SDL_GetError() << std::endl;
            return false;
        }
        SDL_SetTextureBlendMode(texture_, SDL_BLENDMODE_BLEND); // setup for alpha blending in Particle.Show

        emitter_ = new Emitter(Width() / 2, Height() - 75, texture_);

        return true;
    }

    bool Sketch::Draw(void)
    {
        ClearScreen(kColorBlack);

        auto dx = (float)Utils::Map(MousePosition().x, 0, Width(), -0.2, 0.2);
        auto wind = PVector(dx, 0.0f);
        emitter_->ApplyForce(wind);
        emitter_->Run(this);

        for (int i = 0; i < 3; i++) {
            emitter_->AddParticle();
        }

        // Draw arrow to indicate wind direction/force
        auto scayl = 500;
        auto arrow_position = PVector(Width() / 2, 50);
        auto arrow_size = 4;
        Translate((int)arrow_position.x, (int)arrow_position.y);
        RotateRadians(wind.Heading());
        auto length = (int)(wind.Mag() * scayl);
        DrawLine(0, 0, length, 0, kColorWhite);
        DrawLine(length, 0, length - arrow_size, +arrow_size / 2, kColorWhite);
        DrawLine(length, 0, length - arrow_size, -arrow_size / 2, kColorWhite);

        return true;
    }

    void Sketch::Cleanup(void)
    {
        SDL_DestroyTexture(texture_);
    }
}

// END
