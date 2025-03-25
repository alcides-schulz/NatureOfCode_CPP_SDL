#include "Example_05_01_Vehicle.h"

namespace nature_of_code_chapter_05_example_01
{
    void Vehicle::Update(void)
    {
        velocity_.Add(acceleration_);
        velocity_.Limit(max_speed_);
        position_.Add(velocity_);
        acceleration_.Mult(0);
    }

    void Vehicle::ApplyForce(PVector force)
    {
        acceleration_.Add(force);
    }

    void Vehicle::Seek(PVector target)
    {
        auto desired = PVector::Sub(target, position_);
        desired.SetMag(max_speed_);
        auto steer = PVector::Sub(desired, velocity_);
        steer.Limit(max_force_);
        ApplyForce(steer);
    }

    void Vehicle::Show(SDL_Framework *framework)
    {
        framework->Translate(position_.x, position_.y);
        auto angle = velocity_.Heading();
        framework->Rotate(angle);
        SDL_Point vertices[] = { 
            {r_ * 2, 0}, 
            {-r_ * 2, -r_}, 
            {-r_ * 2, r_},
            {r_ * 2, 0},
        };
        framework->Stroke(kColorBlack);
        framework->Lines(vertices, sizeof(vertices) / sizeof(SDL_Point));
    }
}
 
// END
