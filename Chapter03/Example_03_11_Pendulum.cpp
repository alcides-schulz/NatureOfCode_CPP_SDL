#include "Example_03_11_Pendulum.h"
#include "../Common/Utils.h"
namespace nature_of_code_chapter_03_example_11
{

    void Pendulum::Update(void)
    {
        if (!is_dragging_) {
            auto gravity = 0.4f;
            angle_acceleration_ = ((-1 * gravity) / r_) * sin(angle_);
            angle_velocity_ += angle_acceleration_;
            angle_ += angle_velocity_;
            angle_velocity_ *= damping_;
        }
    }

    void Pendulum::Show(P5SDL *p5sdl)
    {
        bob_ = Vector(r_ * sin(angle_), r_ * cos(angle_));
        bob_.Add(pivot_);
        p5sdl->Stroke(kColorBlack);
        p5sdl->Line(pivot_.x, pivot_.y, bob_.x, bob_.y);
        auto color = is_dragging_ ? kColorBlack : kColorGray;
        p5sdl->Fill(color);
        p5sdl->Circle(bob_.x, bob_.y, (int)(ball_r_ * 2));
    }

    void Pendulum::HandleClick(int mouse_x, int mouse_y)
    {
        if (!is_dragging_) {
            auto distance = Vector::Distance(Vector(mouse_x, mouse_y), bob_);
            if (distance < ball_r_) {
                is_dragging_ = true;
            }
        }
    }

    void Pendulum::HandleDrag(int mouse_x, int mouse_y)
    {
        if (is_dragging_) {
            auto diff = Vector::Sub(pivot_, Vector(mouse_x, mouse_y));
            angle_ = atan2(-1 * diff.y, diff.x) - Utils::Radians(90);
        }
    }

    void Pendulum::StopDragging(void)
    {
        if (is_dragging_) {
            is_dragging_ = false;
            angle_velocity_ = 0;
        }
    }

}
 
// END
