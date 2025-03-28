#include "Example_05_06_Path.h"

namespace nature_of_code_chapter_05_example_06
{
    Path::Path(SDL_Framework *framework)
    {
        radius_ = 20;
        start_ = Vector(0, framework->Height() / 3);
        end_ = Vector(framework->Width(), (2 * framework->Height()) / 3);
    }

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
