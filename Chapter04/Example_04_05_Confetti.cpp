#include "Example_04_05_Confetti.h"

namespace nature_of_code_chapter_04_example_05
{
    void Confetti::Show(SDL_Framework *framework)
    {
        auto angle = Utils::Map(position_.x, 0, framework->Width(), 0, M_PI * 2 * 2);
        
        framework->RectMode(kRectCenter);
        framework->Stroke({ kColorBlack.r, kColorBlack.g, kColorBlack.b, (Uint8)life_span_ });
        framework->Rotate(angle);
        framework->Translate(position_.x, position_.y);
        framework->Rect((int)position_.x, (int)position_.y, 8, 8);
        framework->ResetMatrix();
    }
}

// END
