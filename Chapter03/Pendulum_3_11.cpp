#include "Pendulum_3_11.h"
#include "../Common/Utils.h"

void Pendulum_3_11::Update(void)
{
    if (!is_dragging_) {
        auto gravity = 0.4f;
        angle_acceleration_ = ((-1 * gravity) / r_) * sin(angle_);
        angle_velocity_ += angle_acceleration_;
        angle_ += angle_velocity_;
        angle_velocity_ *= damping_;
    }
}

void Pendulum_3_11::Show(SDL_Framework *framework)
{
    bob_ = PVector(r_ * sin(angle_), r_ * cos(angle_));
    bob_.Add(pivot_);
    framework->DrawLine(pivot_.x, pivot_.y, bob_.x, bob_.y, kColorBlack);
    auto color = is_dragging_ ? kColorBlack : kColorGray;
    framework->DrawCircle(bob_.x, bob_.y, (int)(ball_r_ * 2), color, true);
}

void Pendulum_3_11::HandleClick(int mouse_x, int mouse_y)
{
    if (!is_dragging_) {
        auto distance = PVector::Distance(PVector(mouse_x, mouse_y), bob_);
        if (distance < ball_r_) {
            is_dragging_ = true;
        }
    }
}

void Pendulum_3_11::HandleDrag(int mouse_x, int mouse_y)
{
    if (is_dragging_) {
        auto diff = PVector::Sub(pivot_, PVector(mouse_x, mouse_y));
        angle_ = atan2(-1 * diff.y, diff.x) - Utils::Radians(90);
    }
}

void Pendulum_3_11::StopDragging(void)
{
    if (is_dragging_) {
        is_dragging_ = false;
        angle_velocity_ = 0;
    }
}

// EOF