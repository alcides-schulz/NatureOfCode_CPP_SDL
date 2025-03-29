#include "Example_02_02_Mover.h"

namespace nature_of_code_chapter_02_example_02
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
        p5sdl->Circle(position_.x, position_.y, mass_ * 16);
    }
    
    void Mover::CheckEdges(P5SDL *p5sdl)
    {
        if (position_.x > p5sdl->Width()) {
            position_.x = (float)p5sdl->Width();
            velocity_.x *= -1;
        }
        else if (position_.x < 0) {
            position_.x = 0;
            velocity_.x *= -1;
        }
        if (position_.y > p5sdl->Height()) {
            position_.y = (float)p5sdl->Height();
            velocity_.y *= -1;
        }
        else if (position_.y < 0) {
            position_.y = 0;
            velocity_.y *= -1;
        }
    }
    
}

// END
