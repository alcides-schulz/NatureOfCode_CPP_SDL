#include "Example_03_11_Pendulum.h"
#include "../Common/Utils.h"
namespace nature_of_code_chapter_03_example_11
{

    void Pendulum::Update(void)
    {
        if (!_is_dragging) {
            auto gravity = 0.4f;
            _angle_acceleration = ((-1 * gravity) / _r) * sin(_angle);
            _angle_velocity += _angle_acceleration;
            _angle += _angle_velocity;
            _angle_velocity *= _damping;
        }
    }

    void Pendulum::Show(P5SDL *p5sdl)
    {
        _bob = Vector(_r * sin(_angle), _r * cos(_angle));
        _bob.Add(_pivot);
        p5sdl->Stroke(kColorBlack);
        p5sdl->Line(_pivot.x, _pivot.y, _bob.x, _bob.y);
        auto color = _is_dragging ? kColorBlack : kColorGray;
        p5sdl->Fill(color);
        p5sdl->Circle(_bob.x, _bob.y, (int)(_ball_r * 2));
    }

    void Pendulum::HandleClick(int mouse_x, int mouse_y)
    {
        if (!_is_dragging) {
            auto distance = Vector::Distance(Vector(mouse_x, mouse_y), _bob);
            if (distance < _ball_r) {
                _is_dragging = true;
            }
        }
    }

    void Pendulum::HandleDrag(int mouse_x, int mouse_y)
    {
        if (_is_dragging) {
            auto diff = Vector::Sub(_pivot, Vector(mouse_x, mouse_y));
            _angle = atan2(-1 * diff.y, diff.x) - Utils::Radians(90);
        }
    }

    void Pendulum::StopDragging(void)
    {
        if (_is_dragging) {
            _is_dragging = false;
            _angle_velocity = 0;
        }
    }

}
 
// END
