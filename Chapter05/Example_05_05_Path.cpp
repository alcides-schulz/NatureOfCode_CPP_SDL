#include "Example_05_05_Path.h"

namespace nature_of_code_chapter_05_example_05
{
    void Path::Show(SDL_Framework *framework)
    {
        framework->Stroke(kColorLightGray);
        framework->StrokeWeight(radius_ * 2);
        framework->Line(start_.x, start_.y, end_.x, end_.y);
        framework->Stroke(kColorBlack);
        framework->StrokeWeight(2);
        framework->Line(start_.x, start_.y, end_.x, end_.y);
    }
}

// END
