#include "Example_04_05_Confetti.h"

namespace nature_of_code_chapter_04_example_05
{
    void Confetti::Show(P5SDL *p5sdl)
    {
        auto angle = Utils::Map(_position.x, 0, p5sdl->Width(), 0, M_PI * 2 * 2);

        p5sdl->RectMode(kRectCenter);
        p5sdl->StrokeWeight(0);
        p5sdl->Fill(127, _life_span);
        p5sdl->Push();
        p5sdl->Translate(_position.x, _position.y);
        p5sdl->Rotate(angle);
        p5sdl->Square(0, 0, 8);
        p5sdl->Pop();
    }
}

// END
