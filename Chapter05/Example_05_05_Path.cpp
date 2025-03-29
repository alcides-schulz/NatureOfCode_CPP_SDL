#include "Example_05_05_Path.h"

namespace nature_of_code_chapter_05_example_05
{
    void Path::Show(SDL_Framework *framework)
    {
        framework->Stroke(200);
        framework->StrokeWeight(radius_ * 2);
        framework->Line(start_.x, start_.y, end_.x, end_.y);
        framework->Stroke(0);
        framework->StrokeWeight(1);
        framework->Line(start_.x, start_.y, end_.x, end_.y);
    }
}

// END
