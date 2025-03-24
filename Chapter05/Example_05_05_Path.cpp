#include "Example_05_05_Path.h"

namespace nature_of_code_chapter_05_example_05
{
    void Path::Show(SDL_Framework *framework)
    {
        framework->StrokeWeight(radius_ * 2);
        framework->DrawLine(start_.x, start_.y, end_.x, end_.y, kColorLightGray);
        framework->StrokeWeight(1);
        framework->DrawLine(start_.x, start_.y, end_.x, end_.y, kColorBlack);
    }
}

// END
