#include "Example_03_07_Oscillator.h"

namespace nature_of_code_chapter_03_example_07
{
    void Oscillator::Update()
    {
        _angle.Add(_angle_velocity);
    }

    void Oscillator::Show(P5SDL *p5sdl)
    {
        auto x = static_cast<int>(std::sin(_angle.x) * _amplitude.x);
        auto y = static_cast<int>(std::sin(_angle.y) * _amplitude.y);

        p5sdl->Translate(p5sdl->Width() / 2, p5sdl->Height() / 2);
        p5sdl->Stroke(kColorBlack);
        p5sdl->Line(0, 0, x, y);
        p5sdl->Fill(127);
        p5sdl->Circle(x, y, 32);
        p5sdl->ResetMatrix();
    }

}

// END
