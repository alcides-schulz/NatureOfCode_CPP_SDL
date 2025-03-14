#include "Mover_3_2.h"

void Mover_3_2::ApplyForce(PVector force)
{
    PVector temp = PVector(force);
    temp.Div((float)mass_);
    acceleration_.Add(temp);
}

void Mover_3_2::Update(void)
{
    velocity_.Add(acceleration_);
    position_.Add(velocity_);
    
    angle_acceleration_ = acceleration_.x / 10.0f;
    angle_velocity_ += angle_acceleration_;
    angle_velocity_ = std::fmaxf(-0.1f, std::fminf(0.1f, angle_velocity_));
    angle_ += angle_velocity_;

    acceleration_.Mult(0);
    angle_acceleration_ = 0;
}

void Mover_3_2::Display(SDL_Framework *framework)
{
    int line_x1 = 0;
    int line_y1 = 0;
    int line_x2 = radius_;
    int line_y2 = 0;

    framework->Translate((int)position_.x, (int)position_.y);
    framework->RotateRadians(angle_);
    framework->DrawCircle(0, 0, radius_ * 2, kColorGray, true);
    framework->DrawLine(line_x1, line_y1, line_x2, line_y2, kColorBlack);
    framework->ResetMatrix();
}

// EOF