#include "Example_02_04_Mover.h"

namespace nature_of_code_chapter_02_example_04
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
    
    void Mover::Show(SDL_Framework *framework)
    {
        framework->Stroke(0);
        framework->Fill(127);
        framework->Circle(position_.x, position_.y, radius_ * 2);
    }
    
    bool Mover::ContactEdge(SDL_Framework *framework)
    {
        return position_.y > framework->Height() - radius_ - 1;
    }
    
    void Mover::BounceEdges(SDL_Framework *framework)
    {
        float bounce = -0.9f;
        if (position_.x > framework->Width() - radius_) {
            position_.x = (float)(framework->Width() - radius_);
            velocity_.x *= bounce;
        }
        else if (position_.x < radius_) {
            position_.x = (float)radius_;
            velocity_.x *= bounce;
        }
        if (position_.y > framework->Height() - radius_) {
            position_.y = (float)(framework->Height() - radius_);
            velocity_.y *= bounce;
        }
    }
    
}

// END
