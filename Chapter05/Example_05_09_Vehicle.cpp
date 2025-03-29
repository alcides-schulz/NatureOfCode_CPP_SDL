#include "Example_05_09_Vehicle.h"

namespace nature_of_code_chapter_05_example_09
{
    static Vector GetNormalPoint(Vector position, Vector a, Vector b);

    Vehicle::Vehicle(SDL_Framework *framework, int x, int y, float max_speed, float max_force)
    {
        framework_ = framework;
        position_ = Vector(x, y);
        acceleration_ = Vector(0, 0);
        velocity_ = Vector(2, 0);
        r_ = 4;
        max_speed_ = max_speed != 0 ? max_speed : 4;
        max_force_ = max_force != 0 ? max_force : 0.1f;
    };

    void Vehicle::Run()
    {
        Update();
        Show();
    }

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

    void Vehicle::Borders()
    {
        //if (position_.x > path->GetEnd().x + r_) {
        //    position_.x = path->GetStart().x - r_;
        //    position_.y = path->GetStart().y + (position_.y - path->GetEnd().y);
        //}
    }

    void Vehicle::Show()
    {
        framework_->Translate(position_.x, position_.y);
        auto angle = velocity_.Heading();
        framework_->Rotate(angle);
        SDL_Point vertices[] = { 
            {r_ * 2, 0}, 
            {-r_ * 2, -r_}, 
            {-r_ * 2, r_},
            {r_ * 2, 0},
        };
        framework_->Stroke(kColorBlack);
        framework_->Lines(vertices, sizeof(vertices) / sizeof(SDL_Point));
        framework_->ResetMatrix();
    }

    static Vector GetNormalPoint(Vector position, Vector a, Vector b)
    {
        auto vectorA = Vector::Sub(position, a);
        auto vectorB = Vector::Sub(b, a);
        vectorB.Normalize();
        vectorB.Mult(vectorA.Dot(vectorB));
        auto normal_point = Vector::Add(a, vectorB);
        return normal_point;
    }
}
 
// END
