#include "Example_05_08_Path.h"

namespace nature_of_code_chapter_05_example_08
{
    Path::Path()
    {
        radius_ = 20;
    }

    void Path::AddPoint(float x, float y)
    {
        points_.push_back(Vector(x, y));
    }

    void Path::Show(P5SDL *p5sdl)
    {
        p5sdl->Stroke(200);
        p5sdl->StrokeWeight(radius_ * 2);
        for (int i = 1; i < points_.size(); i++) {
            p5sdl->Line(points_[i - 1].x, points_[i - 1].y, points_[i].x, points_[i].y);
        }
        p5sdl->Stroke(0);
        p5sdl->StrokeWeight(1);
        for (int i = 1; i < points_.size(); i++) {
            p5sdl->Line(points_[i - 1].x, points_[i - 1].y, points_[i].x, points_[i].y);
        }
    }
}

// END
