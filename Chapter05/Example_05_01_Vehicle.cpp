#include "Example_05_01_Vehicle.h"

namespace nature_of_code_chapter_05_example_01
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

    void Vehicle::Seek(Vector target)
    {
        auto desired = Vector::Sub(target, _position);
        desired.SetMag(_max_speed);
        auto steer = Vector::Sub(desired, _velocity);
        steer.Limit(_max_force);
        ApplyForce(steer);
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
