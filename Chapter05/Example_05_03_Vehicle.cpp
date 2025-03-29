#include "Example_05_03_Vehicle.h"

namespace nature_of_code_chapter_05_example_03
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

    void Vehicle::Boundaries(P5SDL *p5sdl, int offset)
    {
        Vector *desired = nullptr;
        if (position_.x < offset) {
            desired = new Vector(max_speed_, velocity_.y);
        }
        else if (position_.x > p5sdl->Width() - offset) {
            desired = new Vector(-max_speed_, velocity_.y);
        }
        if (position_.y < offset) {
            desired = new Vector(this->velocity_.x, this->max_speed_);
        }
        else if (position_.y > p5sdl->Height() - offset) {
            desired = new Vector(this->velocity_.x, -this->max_speed_);
        }
        if (desired != nullptr) {
            desired->Normalize();
            desired->Mult(max_speed_);
            auto steer = Vector::Sub(*desired, velocity_);
            steer.Limit(max_force_);
            ApplyForce(steer);
            delete desired;
        }
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
