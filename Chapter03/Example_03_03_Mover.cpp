#include "Example_03_03_Mover.h"

namespace nature_of_code_chapter_03_example_03
{
    void Mover::Update(P5SDL *p5sdl)
    {
        auto direction = Vector(p5sdl->MousePosition().x, p5sdl->MousePosition().y);
        direction.Sub(_position);
        direction.Normalize();
        direction.Mult(0.5f);

        _acceleration = direction;

        _velocity.Add(_acceleration);
        _velocity.Limit(_top_speed);
        _position.Add(_velocity);
    }

    void Mover::Show(P5SDL *p5sdl)
    {
        auto angle = _velocity.Heading();
        p5sdl->Rotate(angle);
        p5sdl->Translate(_position.x, _position.y);
        p5sdl->RectMode(kRectCenter);
        p5sdl->Rect(0, 0, 40, 20);
    }

    void Mover::CheckEdges(P5SDL *p5sdl)
    {
        if (_position.x > p5sdl->Width())
            _position.x = 0;
        else if (_position.x < 0)
            _position.x = static_cast<float>(p5sdl->Width());
        if (_position.y > p5sdl->Height())
            _position.y = 0;
        else if (_position.y < 0)
            _position.y = static_cast<float>(p5sdl->Height());
    }

}
 
// END
