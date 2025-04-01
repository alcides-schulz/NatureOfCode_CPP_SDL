#include "Example_04_05_Confetti.h"

namespace nature_of_code_chapter_04_example_05
{
    void Confetti::Show(P5SDL *p5sdl)
    {
        auto angle = Utils::Map(_position.x, 0, p5sdl->Width(), 0, M_PI * 2 * 2);
        
        p5sdl->RectMode(kRectCenter);
        p5sdl->Stroke({ kColorBlack.r, kColorBlack.g, kColorBlack.b, (Uint8)_life_span });
        p5sdl->StrokeWeight(2);
        p5sdl->Rotate(angle);
        p5sdl->Translate(_position.x, _position.y);
        p5sdl->Rect(0, 0, 8, 8);
        p5sdl->ResetMatrix();
    }
}

// END
