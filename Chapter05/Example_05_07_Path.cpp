#include "Example_05_07_Path.h"

namespace nature_of_code_chapter_05_example_07
{
    Path::Path()
    {
        radius_ = 20;
    }

    void Path::AddPoint(int x, int y)
    {
        points_.push_back(Vector(x, y));
    }

    void Path::Show(SDL_Framework *framework)
    {
        framework->Stroke(200);
        framework->StrokeWeight(radius_ * 2);
        for (int i = 1; i < points_.size(); i++) {
            framework->Line(points_[i - 1].x, points_[i - 1].y, points_[i].x, points_[i].y);
        }
        framework->Stroke(0);
        framework->StrokeWeight(2);
        for (int i = 1; i < points_.size(); i++) {
            framework->Line(points_[i - 1].x, points_[i - 1].y, points_[i].x, points_[i].y);
        }
    }
}

// END
