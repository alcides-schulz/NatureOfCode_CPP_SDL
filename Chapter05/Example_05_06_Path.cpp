#include "Example_05_06_Path.h"

namespace nature_of_code_chapter_05_example_06
{
    Path::Path(P5SDL *p5sdl)
    {
        _radius = 20;
        _start = Vector(0, p5sdl->Height() / 3);
        _end = Vector(p5sdl->Width(), (2 * p5sdl->Height()) / 3);
    }

    void Path::Show(P5SDL *p5sdl)
    {
        p5sdl->Stroke(200);
        p5sdl->StrokeWeight(_radius * 2);
        p5sdl->Line(_start.x, _start.y, _end.x, _end.y);
        p5sdl->Stroke(0);
        p5sdl->StrokeWeight(1);
        p5sdl->Line(_start.x, _start.y, _end.x, _end.y);
    }
}

// END
