#include "Example_03_10_Bob.h"

namespace nature_of_code_chapter_03_example_10
{
    void Bob::ApplyForce(Vector force)
    {
        auto temp = force.Copy();
        temp.Div(_mass);
        _acceleration.Add(temp);
    }

    void Bob::Update(P5SDL *p5sdl)
    {
        _velocity.Add(_acceleration);
        _velocity.Mult(_damping);
        _position.Add(_velocity);
        _acceleration.Mult(0);
    }

    void Bob::Show(P5SDL *p5sdl)
    {
        auto color = _is_dragging ? kColorBlack : kColorGray;
        p5sdl->Fill(color);
        p5sdl->Circle(_position.x, _position.y, (int)(_mass * 2));
    }

    void Bob::HandleClick(int mouse_x, int mouse_y)
    {
        if (!_is_dragging) {
            auto distance = Vector::Distance(Vector(mouse_x, mouse_y), _position);
            if (distance < _mass) {
                _is_dragging = true;
                _drag_offset.x = _position.x - mouse_x;
                _drag_offset.y = _position.y - mouse_y;
            }
        }
    }

    void Bob::HandleDrag(int mouse_x, int mouse_y)
    {
        if (_is_dragging) {
            _position.x = mouse_x + _drag_offset.x;
            _position.y = mouse_y + _drag_offset.y;
        }
    }

    void Bob::StopDragging(void)
    {
        _is_dragging = false;
    }

}
    
// END
