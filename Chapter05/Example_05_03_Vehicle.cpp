#include "Example_05_03_Vehicle.h"

namespace nature_of_code_chapter_05_example_03
{
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

    void Vehicle::Boundaries(P5SDL *p5sdl, int offset)
    {
        Vector *desired = nullptr;
        if (_position.x < offset) {
            desired = new Vector(_max_speed, _velocity.y);
        }
        else if (_position.x > p5sdl->Width() - offset) {
            desired = new Vector(-_max_speed, _velocity.y);
        }
        if (_position.y < offset) {
            desired = new Vector(this->_velocity.x, this->_max_speed);
        }
        else if (_position.y > p5sdl->Height() - offset) {
            desired = new Vector(this->_velocity.x, -this->_max_speed);
        }
        if (desired != nullptr) {
            desired->Normalize();
            desired->Mult(_max_speed);
            auto steer = Vector::Sub(*desired, _velocity);
            steer.Limit(_max_force);
            ApplyForce(steer);
            delete desired;
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
    }
}
 
// END
