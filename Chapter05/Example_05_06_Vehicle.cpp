#include "Example_05_06_Vehicle.h"

namespace nature_of_code_chapter_05_example_06
{
    static PVector GetNormalPoint(PVector position, PVector a, PVector b);

    Vehicle::Vehicle(int x, int y, float max_speed, float max_force)
    {
        position_ = PVector(x, y);
        acceleration_ = PVector(0, 0);
        velocity_ = PVector(2, 0);
        r_ = 4;
        max_speed_ = max_speed;
        max_force_ = max_force;
    };

    void Vehicle::Run(SDL_Framework *framework)
    {
        Update();
        Show(framework);
    }

    void Vehicle::Follow(Path *path, SDL_Framework *framework, bool debug)
    {
        auto future = velocity_.Clone();
        future.SetMag(25);
        future.Add(position_);

        auto normal_point = GetNormalPoint(future, path->GetStart(), path->GetEnd());

        auto b = PVector::Sub(path->GetEnd(), path->GetStart());
        b.SetMag(25);
        auto target = PVector::Add(normal_point, b);

        auto distance = PVector::Distance(normal_point, future);
        if (distance > path->GetRadius())
            Seek(target);

        if (debug) {
            framework->Fill(127);
            framework->Stroke(0);
            framework->Line(position_.x, position_.y, future.x, future.y);
            framework->Circle(future.x, future.y, 4);

            framework->Line(future.x, future.y, normal_point.x, normal_point.y);
            framework->Circle(normal_point.x, normal_point.y, 4);
            framework->Stroke(0);
            if (distance > path->GetRadius())
                framework->Fill({ 255, 0, 0, 255 });
            framework->Circle(target.x + b.x, target.y + b.y, 8);
        }
    }

    void Vehicle::Seek(PVector target)
    {
        auto desired = PVector::Sub(target, position_);
        if (desired.Mag() == 0)
            return;

        desired.Normalize();
        desired.Mult(max_speed_);

        auto steer = PVector::Sub(desired, velocity_);
        steer.Limit(max_force_);

        ApplyForce(steer);
    }

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

    void Vehicle::Borders(Path *path)
    {
        if (position_.x > path->GetEnd().x + r_) {
            position_.x = path->GetStart().x - r_;
            position_.y = path->GetStart().y + (position_.y - path->GetEnd().y);
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
        framework->ResetMatrix();
    }

    static PVector GetNormalPoint(PVector position, PVector a, PVector b)
    {
        auto vectorA = PVector::Sub(position, a);
        auto vectorB = PVector::Sub(b, a);
        vectorB.Normalize();
        vectorB.Mult(vectorA.Dot(vectorB));
        auto normal_point = PVector::Add(a, vectorB);
        return normal_point;
    }
}
 
// END
