#include "Example_05_04_Vehicle.h"

namespace nature_of_code_chapter_05_example_04
{

    void Vehicle::Run(P5SDL *p5sdl)
    {
        Update();
        Borders(p5sdl);
        Show(p5sdl);
    }

    void Vehicle::Follow(FlowField *flowfield)
    {
        auto desired = flowfield->Lookup(_position);
        desired.Mult(_max_speed);
        auto steer = Vector::Sub(desired, _velocity);
        steer.Limit(_max_force);
        ApplyForce(steer);
    }
    
    void Vehicle::ApplyForce(Vector force)
    {
        _acceleration.Add(force);
    }

    void Vehicle::Update(void)
    {
        _velocity.Add(_acceleration);
        _velocity.Limit(_max_speed);
        _position.Add(_velocity);
        _acceleration.Mult(0);
    }
    
    void Vehicle::Borders(P5SDL *p5sdl)
    {
        if (_position.x < -_r) _position.x = (float)(p5sdl->Width() + _r);
        if (_position.y < -_r) _position.y = (float)(p5sdl->Height() + _r);
        if (_position.x > p5sdl->Width() + _r) _position.x = (float)-_r;
        if (_position.y > p5sdl->Height() + _r) _position.y = (float)-_r;
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
}
 
// END
