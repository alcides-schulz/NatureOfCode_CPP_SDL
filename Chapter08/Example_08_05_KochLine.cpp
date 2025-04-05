#include "Example_08_05_KochLine.h"

namespace nature_of_code_chapter_08_example_05
{
    KochLine::KochLine(P5SDL *p5sdl, Vector a, Vector b)
    {
        _p5sdl = p5sdl;
        _start = a.Copy();
        _end = b.Copy();
    }

    void KochLine::Show(void)
    {
        _p5sdl->Stroke(0);
        _p5sdl->StrokeWeight(2);
        _p5sdl->Line(_start.x, _start.y, _end.x, _end.y);
    }

    vector<Vector> KochLine::KochPoints(void)
    {
        auto a = _start.Copy();
        auto e = _end.Copy();

        auto v = Vector::Sub(_end, _start);
        v.Mult(1.0f / 3.0f);

        auto b = Vector::Add(a, v);
        auto d = Vector::Add(b, v);

        v.Rotate(-M_PI / 3.0f);
        auto c = Vector::Add(b, v);

        return { a, b, c, d, e };
    }

}

// END
