#include "Example_01_07_Mover.h"

namespace nature_of_code_chapter_01_example_07
{
    void Mover::Update(void)
    {
        position_.Add(velocity_);
    }
    
    void Mover::Show(SDL_Framework *framework)
    {
        framework->Stroke(0);
        framework->Fill(127);
        framework->Circle(position_.x, position_.y, 48);
    }
    
    void Mover::CheckEdges(SDL_Framework *framework)
    {
        if (position_.x > framework->Width())
            position_.x = 0;
        else if (position_.x < 0)
            position_.x = (float)framework->Width();
        if (position_.y > framework->Height())
            position_.y = 0;
        else if (position_.y < 0)
            position_.y = (float)framework->Height();
    }
    
}

// END
