#include "Example_03_03_Mover.h"

namespace nature_of_code_chapter_03_example_03
{
    void Mover::Update(P5SDL *p5sdl)
    {
        auto direction = Vector(p5sdl->MousePosition().x, p5sdl->MousePosition().y);
        direction.Sub(position_);
        direction.Normalize();
        direction.Mult(0.5f);

        acceleration_ = direction;

        velocity_.Add(acceleration_);
        velocity_.Limit(top_speed_);
        position_.Add(velocity_);
    }

    void Mover::Show(P5SDL *p5sdl)
    {
        auto angle = velocity_.Heading();
        p5sdl->Rotate(angle);
        p5sdl->Translate(position_.x, position_.y);
        p5sdl->RectMode(kRectCenter);
        p5sdl->Rect(0, 0, 40, 20);
    }

    void Mover::CheckEdges(P5SDL *p5sdl)
    {
        if (position_.x > p5sdl->Width())
            position_.x = 0;
        else if (position_.x < 0)
            position_.x = static_cast<float>(p5sdl->Width());
        if (position_.y > p5sdl->Height())
            position_.y = 0;
        else if (position_.y < 0)
            position_.y = static_cast<float>(p5sdl->Height());
    }

}
 
// END
