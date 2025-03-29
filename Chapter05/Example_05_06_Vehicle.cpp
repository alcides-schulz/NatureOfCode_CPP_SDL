#include "Example_05_06_Vehicle.h"

namespace nature_of_code_chapter_05_example_06
{
    static Vector GetNormalPoint(Vector position, Vector a, Vector b);

    Vehicle::Vehicle(int x, int y, float max_speed, float max_force)
    {
        _position = Vector(x, y);
        _acceleration = Vector(0, 0);
        _velocity = Vector(2, 0);
        _r = 4;
        _max_speed = max_speed;
        _max_force = max_force;
    };

    void Vehicle::Run(P5SDL *p5sdl)
    {
        Update();
        Show(p5sdl);
    }

    void Vehicle::Follow(Path *path, P5SDL *p5sdl, bool debug)
    {
        auto future = _velocity.Clone();
        future.SetMag(25);
        future.Add(_position);

        auto normal_point = GetNormalPoint(future, path->GetStart(), path->GetEnd());

        auto b = Vector::Sub(path->GetEnd(), path->GetStart());
        b.SetMag(25);
        auto target = Vector::Add(normal_point, b);

        auto distance = Vector::Distance(normal_point, future);
        if (distance > path->GetRadius())
            Seek(target);

        if (debug) {
            p5sdl->Fill(127);
            p5sdl->Stroke(0);
            p5sdl->Line(_position.x, _position.y, future.x, future.y);
            p5sdl->Circle(future.x, future.y, 4);

            p5sdl->Line(future.x, future.y, normal_point.x, normal_point.y);
            p5sdl->Circle(normal_point.x, normal_point.y, 4);
            p5sdl->Stroke(0);
            if (distance > path->GetRadius())
                p5sdl->Fill({ 255, 0, 0, 255 });
            p5sdl->Circle(target.x + b.x, target.y + b.y, 8);
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
