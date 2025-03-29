#include "Example_05_08_Path.h"

namespace nature_of_code_chapter_05_example_08
{
    Path::Path()
    {
        _radius = 20;
    }

    void Path::AddPoint(float x, float y)
    {
        _points.push_back(Vector(x, y));
    }

    void Path::Show(P5SDL *p5sdl)
    {
        p5sdl->Stroke(200);
        p5sdl->StrokeWeight(_radius * 2);
        for (int i = 1; i < _points.size(); i++) {
            p5sdl->Line(_points[i - 1].x, _points[i - 1].y, _points[i].x, _points[i].y);
        }
        p5sdl->Stroke(0);
        p5sdl->StrokeWeight(1);
        for (int i = 1; i < _points.size(); i++) {
            p5sdl->Line(_points[i - 1].x, _points[i - 1].y, _points[i].x, _points[i].y);
        }
    }
}

// END
