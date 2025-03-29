#include "Example_05_06_Path.h"

namespace nature_of_code_chapter_05_example_06
{
    Path::Path(P5SDL *p5sdl)
    {
        radius_ = 20;
        start_ = Vector(0, p5sdl->Height() / 3);
        end_ = Vector(p5sdl->Width(), (2 * p5sdl->Height()) / 3);
    }

    void Path::Show(P5SDL *p5sdl)
    {
        p5sdl->Stroke(200);
        p5sdl->StrokeWeight(radius_ * 2);
        p5sdl->Line(start_.x, start_.y, end_.x, end_.y);
        p5sdl->Stroke(0);
        p5sdl->StrokeWeight(1);
        p5sdl->Line(start_.x, start_.y, end_.x, end_.y);
    }
}

// END
