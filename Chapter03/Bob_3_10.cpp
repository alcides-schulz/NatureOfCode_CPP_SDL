#include "Bob_3_10.h"

void Bob_3_10::ApplyForce(PVector force)
{
    auto temp = force.Clone();
    temp.Div(mass_);
    acceleration_.Add(temp);
}

void Bob_3_10::Update(SDL_Framework *framework)
{
    velocity_.Add(acceleration_);
    velocity_.Mult(damping_);
    position_.Add(velocity_);
    acceleration_.Mult(0);
}

void Bob_3_10::Show(SDL_Framework *framework)
{
    auto color = is_dragging_ ? kColorBlack : kColorGray;
    framework->DrawCircle(position_.x, position_.y, (int)(mass_ * 2), color, true);
}

void Bob_3_10::HandleClick(int mouse_x, int mouse_y)
{
    if (!is_dragging_) {
        auto distance = PVector::Distance(PVector(mouse_x, mouse_y), position_);
        if (distance < mass_) {
            is_dragging_ = true;
            drag_offset_.x = position_.x - mouse_x;
            drag_offset_.y = position_.y - mouse_y;
        }
    }
}

void Bob_3_10::HandleDrag(int mouse_x, int mouse_y)
{
    if (is_dragging_) {
        position_.x = mouse_x + drag_offset_.x;
        position_.y = mouse_y + drag_offset_.y;
    }
}

void Bob_3_10::StopDragging(void)
{
    is_dragging_ = false;
}

// EOF