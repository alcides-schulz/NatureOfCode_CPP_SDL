#include "Example_03_02_Mover.h"

namespace nature_of_code_chapter_03_example_02
{
    void Mover::ApplyForce(Vector force)
    {
        Vector temp = Vector(force);
        temp.Div((float)mass_);
        acceleration_.Add(temp);
    }

    void Mover::Update(void)
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

    void Mover::Show(SDL_Framework *framework)
    {
        int line_x1 = 0;
        int line_y1 = 0;
        int line_x2 = radius_;
        int line_y2 = 0;

        framework->Translate(position_.x, position_.y);
        framework->Rotate(angle_);
        framework->Stroke(kColorBlack);
        framework->Fill(127);
        framework->Circle(0, 0, radius_ * 2);
        framework->Line(line_x1, line_y1, line_x2, line_y2);
        framework->ResetMatrix();
    }
}
 
// END
