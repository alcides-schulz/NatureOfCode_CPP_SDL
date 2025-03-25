#include "Example_02_07_Mover.h"

namespace nature_of_code_chapter_02_example_07
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
    
}

// END
