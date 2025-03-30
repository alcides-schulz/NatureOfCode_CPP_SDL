#include "Example_05_10_Vehicle.h"

namespace nature_of_code_chapter_05_example_10
{
    Vehicle::Vehicle(P5SDL *p5sdl, int x, int y)
    {
        _p5sdl = p5sdl;
        _position = Vector(x, y);
        _acceleration = Vector(0, 0);
        _velocity = Vector(0, 0);
        _r = 6;
        _max_speed = 3;
        _max_force = 0.2f;
    };

    void Vehicle::ApplyBehaviors(vector<Vehicle *> vehicles)
    {
        auto separate_force = Separate(vehicles);
        auto seek_force = Seek(Vector(_p5sdl->MousePosition().x, _p5sdl->MousePosition().y));
        separate_force.Mult(1.5f);
        seek_force.Mult(0.5f);
        ApplyForce(separate_force);
        ApplyForce(seek_force);
    }

    void Vehicle::ApplyForce(Vector force)
    {
        _acceleration.Add(force);
    }

    Vector Vehicle::Separate(vector<Vehicle *> vehicles)
    {
        auto desired_separation = _r * 2;
        auto sum = Vector(0, 0);
        auto count = 0;
        for (auto other : vehicles)
        {
            auto distance = Vector::Distance(_position, other->_position);
            if (this != other && distance < desired_separation) {
                auto diff = Vector::Sub(_position, other->_position);
                diff.SetMag(1.0f / distance);
                sum.Add(diff);
                count++;
            }
        }
        if (count > 0) {
            sum.Div((float)count);
            sum.SetMag(_max_speed);
            sum.Sub(_velocity);
            sum.Limit(_max_force);
        }
        return sum;
    }

    Vector Vehicle::Seek(Vector target)
    {
        auto desired = Vector::Sub(target, _position);
        desired.Normalize();
        desired.Mult(_max_speed);
        auto steer = Vector::Sub(desired, _velocity);
        steer.Limit(_max_force);
        return steer;
    }

    void Vehicle::Update(void)
    {
        _velocity.Add(_acceleration);
        _velocity.Limit(_max_speed);
        _position.Add(_velocity);
        _acceleration.Mult(0);
    }

    void Vehicle::Show()
    {
        _p5sdl->Fill(127);
        _p5sdl->Stroke(0);
        _p5sdl->StrokeWeight(2);
        _p5sdl->Translate(_position.x, _position.y);
        _p5sdl->Circle(0, 0, _r * 2);
        _p5sdl->ResetMatrix();
    }

    void Vehicle::Borders()
    {
        if (_position.x < -_r)
            _position.x = (float)(_p5sdl->Width() + _r);
        if (_position.y < -_r)
            _position.y = (float)(_p5sdl->Height() + _r);
        if (_position.x > _p5sdl->Width() + _r)
            _position.x = (float)-_r;
        if (_position.y > _p5sdl->Height() + _r)
            _position.y = (float)-_r;
    }
}
 
// END
