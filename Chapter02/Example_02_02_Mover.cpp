#include "Example_02_02_Mover.h"

namespace nature_of_code_chapter_02_example_02
{
    void Mover::ApplyForce(PVector force)
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
    
    void Mover::Show(SDL_Framework *framework)
    {
        framework->Stroke(0);
        framework->Fill(127);
        framework->Circle(position_.x, position_.y, mass_ * 16);
    }
    
    void Mover::CheckEdges(SDL_Framework *framework)
    {
        if (position_.x > framework->Width()) {
            position_.x = (float)framework->Width();
            velocity_.x *= -1;
        }
        else if (position_.x < 0) {
            position_.x = 0;
            velocity_.x *= -1;
        }
        if (position_.y > framework->Height()) {
            position_.y = (float)framework->Height();
            velocity_.y *= -1;
        }
        else if (position_.y < 0) {
            position_.y = 0;
            velocity_.y *= -1;
        }
    }
    
}

// END
