#include "Example_05_08_Vehicle.h"

namespace nature_of_code_chapter_05_example_08
{
    static Vector GetNormalPoint(Vector position, Vector a, Vector b);

    Vehicle::Vehicle(int x, int y, float max_speed, float max_force)
    {
        _position = Vector(x, y);
        _acceleration = Vector(0, 0);
        _velocity = Vector(2, 0);
        _r = 4;
        _max_speed = max_speed != 0 ? max_speed : 4;
        _max_force = max_force != 0 ? max_force : 0.1f;
    };

    void Vehicle::Run(P5SDL *p5sdl)
    {
        Update();
        Show(p5sdl);
    }

    void Vehicle::Follow(Path *path, P5SDL *p5sdl, bool debug)
    {
        auto future = _velocity.Clone();
        future.SetMag(50);
        future.Add(_position);

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
            p5sdl->Stroke(0);
            p5sdl->StrokeWeight(1);
            p5sdl->Fill(127);
            p5sdl->Line(_position.x, _position.y, future.x, future.y);
            p5sdl->Circle(future.x, future.y, 4);
            p5sdl->Circle(normal.x, normal.y, 4);
            p5sdl->Line(future.x, future.y, normal.x, normal.y);
            p5sdl->Stroke(0);
            if (world_record > path->GetRadius())
                p5sdl->Fill(kColorRed);
            p5sdl->Circle(target.x, target.y, 8);
        }
    }
  
    void Vehicle::Seek(Vector target)
    {
        auto desired = Vector::Sub(target, _position);
        if (desired.Mag() == 0)
            return;
        desired.Normalize();
        desired.Mult(_max_speed);
        auto steer = Vector::Sub(desired, _velocity);
        steer.Limit(_max_force);
        ApplyForce(steer);
    }

    void Vehicle::Update(void)
    {
        _velocity.Add(_acceleration);
        _velocity.Limit(_max_speed);
        _position.Add(_velocity);
        _acceleration.Mult(0);
    }

    void Vehicle::ApplyForce(Vector force)
    {
        _acceleration.Add(force);
    }

    void Vehicle::Borders(Path *path)
    {
        if (_position.x > path->GetEnd().x + _r) {
            _position.x = path->GetStart().x - _r;
            _position.y = path->GetStart().y + (_position.y - path->GetEnd().y);
        }
    }

    void Vehicle::Show(P5SDL *p5sdl)
    {
        p5sdl->Translate(_position.x, _position.y);
        auto angle = _velocity.Heading();
        p5sdl->Rotate(angle);
        SDL_Point vertices[] = { 
            {_r * 2, 0}, 
            {-_r * 2, -_r}, 
            {-_r * 2, _r},
            {_r * 2, 0},
        };
        p5sdl->Stroke(kColorBlack);
        p5sdl->Lines(vertices, sizeof(vertices) / sizeof(SDL_Point));
        p5sdl->ResetMatrix();
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
