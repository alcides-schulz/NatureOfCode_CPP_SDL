#include "Example_05_02_Vehicle.h"

namespace nature_of_code_chapter_05_example_02
{
    void Vehicle::Update(void)
    {
        velocity_.Add(acceleration_);
        velocity_.Limit(max_speed_);
        position_.Add(velocity_);
        acceleration_.Mult(0);
    }

    void Vehicle::ApplyForce(Vector force)
    {
        acceleration_.Add(force);
    }

    void Vehicle::Arrive(Vector target)
    {
        auto desired = Vector::Sub(target, position_);
        auto current_mag = desired.Mag();
        if (current_mag < 100) {
            auto new_mag = (float)Utils::Map(current_mag, 0, 100, 0, max_speed_);
            desired.SetMag(new_mag);
        }
        else {
            desired.SetMag(max_speed_);
        }
        auto steer = Vector::Sub(desired, velocity_);
        steer.Limit(max_force_);
        ApplyForce(steer);
    }

    void Vehicle::Show(P5SDL *p5sdl)
    {
        p5sdl->Translate(position_.x, position_.y);
        auto angle = velocity_.Heading();
        p5sdl->Rotate(angle);
        SDL_Point vertices[] = { 
            {r_ * 2, 0}, 
            {-r_ * 2, -r_}, 
            {-r_ * 2, r_},
            {r_ * 2, 0},
        };
        p5sdl->Stroke(kColorBlack);
        p5sdl->Lines(vertices, sizeof(vertices) / sizeof(SDL_Point));
    }
}
 
// END
