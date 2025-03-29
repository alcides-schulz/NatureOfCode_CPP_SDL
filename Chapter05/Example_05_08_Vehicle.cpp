#include "Example_05_08_Vehicle.h"

namespace nature_of_code_chapter_05_example_08
{
    static Vector GetNormalPoint(Vector position, Vector a, Vector b);

    Vehicle::Vehicle(int x, int y, float max_speed, float max_force)
    {
        position_ = Vector(x, y);
        acceleration_ = Vector(0, 0);
        velocity_ = Vector(2, 0);
        r_ = 4;
        max_speed_ = max_speed != 0 ? max_speed : 4;
        max_force_ = max_force != 0 ? max_force : 0.1f;
    };

    void Vehicle::Run(SDL_Framework *framework)
    {
        Update();
        Show(framework);
    }

    void Vehicle::Follow(Path *path, SDL_Framework *framework, bool debug)
    {
        auto future = velocity_.Clone();
        future.SetMag(50);
        future.Add(position_);

        bool target_found = false;
        Vector target;
        Vector normal;
        auto world_record = FLT_MAX;

        for (int i = 0; i < path->GetPoints().size() - 1; i++) {
            auto a = path->GetPoints()[i];
            auto b = path->GetPoints()[i + 1];
            auto normal_point = GetNormalPoint(future, a, b);
            if (normal_point.x < a.x || normal_point.x > b.x) {
                normal_point = b.Clone();
            }
            auto distance = Vector::Distance(future, normal_point);
            if (distance < world_record) {
                world_record = distance;
                normal = normal_point;
                target = normal_point.Clone();
                auto direction = Vector::Sub(b, a);
                direction.SetMag(10);
                target.Add(direction);
                target_found = true;
            }
        }

        if (world_record > path->GetRadius() && target_found) {
            Seek(target);
        }

        if (debug && target_found) {
            framework->Stroke(0);
            framework->StrokeWeight(1);
            framework->Fill(127);
            framework->Line(position_.x, position_.y, future.x, future.y);
            framework->Circle(future.x, future.y, 4);
            framework->Circle(normal.x, normal.y, 4);
            framework->Line(future.x, future.y, normal.x, normal.y);
            framework->Stroke(0);
            if (world_record > path->GetRadius())
                framework->Fill(kColorRed);
            framework->Circle(target.x, target.y, 8);
        }
    }
  
    void Vehicle::Seek(Vector target)
    {
        auto desired = Vector::Sub(target, position_);
        if (desired.Mag() == 0)
            return;
        desired.Normalize();
        desired.Mult(max_speed_);
        auto steer = Vector::Sub(desired, velocity_);
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

    void Vehicle::ApplyForce(Vector force)
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
