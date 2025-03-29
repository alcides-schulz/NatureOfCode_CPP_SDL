#include "Example_05_05_Path.h"

namespace nature_of_code_chapter_05_example_05
{
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
