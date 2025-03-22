#include "Example_03_03_Mover.h"

namespace nature_of_code_chapter_03_example_03
{
    void Mover::Update(SDL_Framework *framework)
    {
        auto direction = PVector(framework->MousePosition().x, framework->MousePosition().y);
        direction.Sub(position_);
        direction.Normalize();
        direction.Mult(0.5f);

        acceleration_ = direction;

        velocity_.Add(acceleration_);
        velocity_.Limit(top_speed_);
        position_.Add(velocity_);
    }

    void Mover::Show(SDL_Framework *framework)
    {
        auto angle = velocity_.Heading();
        framework->Translate(position_.x, position_.y);
        framework->RotateRadians(angle);
        framework->DrawRectangle(0, 0, 40, 20, kColorBlack);
    }

    void Mover::CheckEdges(SDL_Framework *framework)
    {
        if (position_.x > framework->Width())
            position_.x = 0;
        else if (position_.x < 0)
            position_.x = static_cast<float>(framework->Width());
        if (position_.y > framework->Height())
            position_.y = 0;
        else if (position_.y < 0)
            position_.y = static_cast<float>(framework->Height());
    }

}
 
// END
