#include "Example_05_04_Vehicle.h"

namespace nature_of_code_chapter_05_example_04
{

    void Vehicle::Run(SDL_Framework *framework)
    {
        Update();
        Borders(framework);
        Show(framework);
    }

    void Vehicle::Follow(FlowField *flowfield)
    {
        auto desired = flowfield->Lookup(position_);
        desired.Mult(max_speed_);
        auto steer = PVector::Sub(desired, velocity_);
        steer.Limit(max_force_);
        ApplyForce(steer);
    }
    
    void Vehicle::ApplyForce(PVector force)
    {
        acceleration_.Add(force);
    }

    void Vehicle::Update(void)
    {
        velocity_.Add(acceleration_);
        velocity_.Limit(max_speed_);
        position_.Add(velocity_);
        acceleration_.Mult(0);
    }
    
    void Vehicle::Borders(SDL_Framework *framework)
    {
        if (position_.x < -r_) position_.x = (float)(framework->Width() + r_);
        if (position_.y < -r_) position_.y = (float)(framework->Height() + r_);
        if (position_.x > framework->Width() + r_) position_.x = (float)-r_;
        if (position_.y > framework->Height() + r_) position_.y = (float)-r_;
    }

    void Vehicle::Show(SDL_Framework *framework)
    {
        framework->Translate(position_.x, position_.y);
        auto angle = velocity_.Heading();
        framework->RotateRadians(angle);
        SDL_Point vertices[] = { 
            {r_ * 2, 0}, 
            {-r_ * 2, -r_}, 
            {-r_ * 2, r_},
            {r_ * 2, 0},
        };
        framework->DrawLines(vertices, sizeof(vertices) / sizeof(SDL_Point), kColorBlack);
        framework->ResetMatrix();
    }
}
 
// END
