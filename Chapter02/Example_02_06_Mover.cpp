#include "Example_02_06_Mover.h"

namespace nature_of_code_chapter_02_example_06
{
    void Mover::ApplyForce(Vector force)
    {
        auto temp = force.Clone();
        temp.Div((float)mass_);
        acceleration_.Add(temp);
    }
    
    void Mover::Update(void)
    {
        velocity_.Add(acceleration_);
        position_.Add(velocity_);
        acceleration_.Mult(0);
    }
    
    void Mover::Show(P5SDL *p5sdl)
    {
        p5sdl->Stroke(0);
        p5sdl->Fill(127);
        p5sdl->Circle(position_.x, position_.y, radius_ * 2);
    }
    
}

// END
