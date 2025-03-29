#include "Example_03_02_Mover.h"

namespace nature_of_code_chapter_03_example_02
{
    void Mover::ApplyForce(Vector force)
    {
        Vector temp = Vector(force);
        temp.Div((float)_mass);
        _acceleration.Add(temp);
    }

    void Mover::Update(void)
    {
        _velocity.Add(_acceleration);
        _position.Add(_velocity);

        _angle_acceleration = _acceleration.x / 10.0f;
        _angle_velocity += _angle_acceleration;
        _angle_velocity = std::fmaxf(-0.1f, std::fminf(0.1f, _angle_velocity));
        _angle += _angle_velocity;

        _acceleration.Mult(0);
        _angle_acceleration = 0;
    }

    void Mover::Show(P5SDL *p5sdl)
    {
        int line_x1 = 0;
        int line_y1 = 0;
        int line_x2 = _radius;
        int line_y2 = 0;

        p5sdl->Translate(_position.x, _position.y);
        p5sdl->Rotate(_angle);
        p5sdl->Stroke(kColorBlack);
        p5sdl->Fill(127);
        p5sdl->Circle(0, 0, _radius * 2);
        p5sdl->Line(line_x1, line_y1, line_x2, line_y2);
        p5sdl->ResetMatrix();
    }
}
 
// END
