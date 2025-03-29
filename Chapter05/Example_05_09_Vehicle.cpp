#include "Example_05_09_Vehicle.h"

namespace nature_of_code_chapter_05_example_09
{
    Vehicle::Vehicle(P5SDL *p5sdl, int x, int y)
    {
        p5sdl_ = p5sdl;
        position_ = Vector(x, y);
        acceleration_ = Vector(0, 0);
        velocity_ = Vector(0, 0);
        r_ = 12;
        max_speed_ = 3;
        max_force_ = 0.2f;
    };

    void Vehicle::ApplyForce(Vector force)
    {
        acceleration_.Add(force);
    }

    void Vehicle::Separate(vector<Vehicle *> vehicles)
    {
        auto desired_separation = r_ * 2;
        auto sum = Vector(0, 0);
        auto count = 0;
        for (auto other : vehicles)
        {
            auto distance = Vector::Distance(position_, other->position_);
            if (this != other && distance < desired_separation) {
                auto diff = Vector::Sub(position_, other->position_);
                diff.SetMag(1.0f / distance);
                sum.Add(diff);
                count++;
            }
        }
        if (count > 0) {
            sum.SetMag(max_speed_);
            auto steer = Vector::Sub(sum, velocity_);
            steer.Limit(max_force_);
            ApplyForce(steer);
        }
    }

    void Vehicle::Update(void)
    {
        velocity_.Add(acceleration_);
        velocity_.Limit(max_speed_);
        position_.Add(velocity_);
        acceleration_.Mult(0);
    }

    void Vehicle::Show()
    {
        p5sdl_->Fill(127);
        p5sdl_->Stroke(0);
        p5sdl_->StrokeWeight(2);
        p5sdl_->Translate(position_.x, position_.y);
        p5sdl_->Circle(0, 0, r_);
        p5sdl_->ResetMatrix();
    }

    void Vehicle::Borders()
    {
        if (position_.x < -r_)
            position_.x = (float)(p5sdl_->Width() + r_);
        if (position_.y < -r_)
            position_.y = (float)(p5sdl_->Height() + r_);
        if (position_.x > p5sdl_->Width() + r_)
            position_.x = (float)-r_;
        if (position_.y > p5sdl_->Height() + r_)
            position_.y = (float)-r_;
    }
}
 
// END
