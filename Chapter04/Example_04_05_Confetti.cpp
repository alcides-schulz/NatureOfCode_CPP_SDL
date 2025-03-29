#include "Example_04_05_Confetti.h"

namespace nature_of_code_chapter_04_example_05
{
    void Confetti::Show(P5SDL *p5sdl)
    {
        auto angle = Utils::Map(position_.x, 0, p5sdl->Width(), 0, M_PI * 2 * 2);
        
        p5sdl->RectMode(kRectCenter);
        p5sdl->Stroke({ kColorBlack.r, kColorBlack.g, kColorBlack.b, (Uint8)life_span_ });
        p5sdl->Rotate(angle);
        p5sdl->Translate(position_.x, position_.y);
        p5sdl->Rect((int)position_.x, (int)position_.y, 8, 8);
        p5sdl->ResetMatrix();
    }
}

// END
