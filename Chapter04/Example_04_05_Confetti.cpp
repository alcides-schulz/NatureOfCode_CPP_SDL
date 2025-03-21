#include "Example_04_05_Confetti.h"

namespace nature_of_code_chapter_04_example_05
{
    void Confetti::Show(SDL_Framework *framework)
    {
        SDL_Color color = kColorBlack;
        auto angle = Utils::Map(position_.x, 0, framework->Width(), 0, M_PI * 2 * 2);
        auto alpha = (Uint8)std::max(0.0f, life_span_);
        framework->RotateRadians(angle);
        framework->DrawRectangle((int)position_.x, (int)position_.y, 8, 8, { color.r, color.g, color.b, alpha });
        framework->ResetMatrix();
    }
}

// END
