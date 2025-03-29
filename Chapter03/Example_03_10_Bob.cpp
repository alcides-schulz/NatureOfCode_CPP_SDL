#include "Example_03_10_Bob.h"

namespace nature_of_code_chapter_03_example_10
{
    void Bob::ApplyForce(Vector force)
    {
        auto temp = force.Clone();
        temp.Div(mass_);
        acceleration_.Add(temp);
    }

    void Bob::Update(P5SDL *p5sdl)
    {
        velocity_.Add(acceleration_);
        velocity_.Mult(damping_);
        position_.Add(velocity_);
        acceleration_.Mult(0);
    }

    void Bob::Show(P5SDL *p5sdl)
    {
        auto color = is_dragging_ ? kColorBlack : kColorGray;
        p5sdl->Fill(color);
        p5sdl->Circle(position_.x, position_.y, (int)(mass_ * 2));
    }

    void Bob::HandleClick(int mouse_x, int mouse_y)
    {
        if (!is_dragging_) {
            auto distance = Vector::Distance(Vector(mouse_x, mouse_y), position_);
            if (distance < mass_) {
                is_dragging_ = true;
                drag_offset_.x = position_.x - mouse_x;
                drag_offset_.y = position_.y - mouse_y;
            }
        }
    }

    void Bob::HandleDrag(int mouse_x, int mouse_y)
    {
        if (is_dragging_) {
            position_.x = mouse_x + drag_offset_.x;
            position_.y = mouse_y + drag_offset_.y;
        }
    }

    void Bob::StopDragging(void)
    {
        is_dragging_ = false;
    }

}
    
// END
