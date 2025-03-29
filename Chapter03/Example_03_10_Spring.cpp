#include "Example_03_10_Spring.h"

namespace nature_of_code_chapter_03_example_10
{
    void Spring::Connect(Bob *bob)
    {
        auto force = Vector::Sub(bob->GetPosition(), anchor_);
        float current_length = force.Mag();
        float stretch = current_length - rest_length_;
        force.SetMag(-1 * k_ * stretch);
        bob->ApplyForce(force);
    }

    void Spring::ConstrainLength(Bob *bob, float min_length, float max_length)
    {
        auto direction = Vector::Sub(bob->GetPosition(), anchor_);
        float length = direction.Mag();
        if (length < min_length) {
            direction.SetMag(min_length);
            bob->SetPosition(Vector::Add(anchor_, direction));
            bob->SetVelocity(Vector(0, 0));
        }
        else if (length > max_length) {
            direction.SetMag(max_length);
            bob->SetPosition(Vector::Add(anchor_, direction));
            bob->SetVelocity(Vector(0, 0));
        }
    }

    void Spring::Show(P5SDL *p5sdl)
    {
        p5sdl->Stroke(0);
        p5sdl->Fill(0);
        p5sdl->Circle(anchor_.x, anchor_.y, 10);
    }

    void Spring::ShowLine(P5SDL *p5sdl, Bob *bob)
    {
        p5sdl->Stroke(kColorBlack);
        p5sdl->Line(bob->GetPosition().x, bob->GetPosition().y, anchor_.x, anchor_.y);
    }

}
 
// END
