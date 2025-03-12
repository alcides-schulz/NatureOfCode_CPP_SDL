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
    
    angle_acceleration_ = acceleration_.x / 1.0f;
    angle_velocity_ += angle_acceleration_;
    angle_velocity_ = std::fmaxf(-2.0f, std::fminf(2.0f, angle_velocity_));
    angle_ += angle_velocity_;

    acceleration_.Mult(0);
    angle_acceleration_ = 0;
}

void Mover_3_2::Display(SDL_Framework *framework)
{
    framework->DrawCircle({ (int)position_.x, (int)position_.y }, radius_ * 2, kColorGray, true);

    int line_x1 = (int)position_.x;
    int line_y1 = (int)position_.y;
    int line_x2 = (int)position_.x + radius_;
    int line_y2 = (int)position_.y;
    double radians = angle_ * M_PI / 180.0;
    int rotated_x2 = (int)(line_x1 + (line_x2 - line_x1) * std::cos(radians) - (line_y2 - line_y1) * std::sin(radians));
    int rotated_y2 = (int)(line_y1 + (line_x2 - line_x1) * std::sin(radians) + (line_y2 - line_y1) * std::cos(radians));

    framework->DrawLine(line_x1, line_y1, rotated_x2, rotated_y2, kColorBlack);
}

// EOF