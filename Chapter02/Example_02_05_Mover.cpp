#include "Example_02_05_Mover.h"

namespace nature_of_code_chapter_02_example_05
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
        framework->Circle(position_.x, position_.y, radius_ * 2);
    }
    
    void Mover::CheckEdges(SDL_Framework *framework)
    {
        if (position_.y > framework->Height() - radius_) {
            position_.y = (float)(framework->Height() - radius_);
            velocity_.y *= -0.9f;
        }
    }
    
}

// END
