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

    void Vehicle::ApplyForce(PVector force)
    {
        acceleration_.Add(force);
    }

    void Vehicle::Boundaries(SDL_Framework *framework, int offset)
    {
        PVector *desired = nullptr;
        if (position_.x < offset) {
            desired = new PVector(max_speed_, velocity_.y);
        }
        else if (position_.x > framework->Width() - offset) {
            desired = new PVector(-max_speed_, velocity_.y);
        }
        if (position_.y < offset) {
            desired = new PVector(this->velocity_.x, this->max_speed_);
        }
        else if (position_.y > framework->Height() - offset) {
            desired = new PVector(this->velocity_.x, -this->max_speed_);
        }
        if (desired != nullptr) {
            desired->Normalize();
            desired->Mult(max_speed_);
            auto steer = PVector::Sub(*desired, velocity_);
            steer.Limit(max_force_);
            ApplyForce(steer);
            delete desired;
        }
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
