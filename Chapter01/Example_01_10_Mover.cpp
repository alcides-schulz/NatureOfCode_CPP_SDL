#include "Example_01_10_Mover.h"

namespace nature_of_code_chapter_01_example_10
{
    void Mover::Update(void)
    {
        velocity_.Add(acceleration_);
        velocity_.Limit(top_speed_);
        position_.Add(velocity_);
    }
    
    void Mover::Show(P5SDL *p5sdl)
    {
        p5sdl->Stroke(0);
        p5sdl->Fill(127);
        p5sdl->Circle(position_.x, position_.y, 48);
    }
    
    void Mover::CheckEdges(P5SDL *p5sdl)
    {
        if (position_.x > p5sdl->Width())
            position_.x = 0;
        else if (position_.x < 0)
            position_.x = (float)p5sdl->Width();
        if (position_.y > p5sdl->Height())
            position_.y = 0;
        else if (position_.y < 0)
            position_.y = (float)p5sdl->Height();
    }
    
}

// END
