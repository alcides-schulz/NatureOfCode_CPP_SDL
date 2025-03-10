#include "Example_1_10.h"

bool Example_1_10::UserInit()
{
    PVector location(WindowWidth() / 2, WindowHeight() / 2);
    PVector velocity(0, 0);
    mover_ = new Mover_1_10(location, velocity);

    return true;
}

bool Example_1_10::UserRender(int elapsed_time)
{
    ClearScreen();

    auto direction = PVector(MousePosition().x, MousePosition().y);
    direction.Sub(mover_->GetLocation());
    direction.Normalize();
    direction.Mult(0.2f);
    mover_->SetAcceleration(direction);

    mover_->Update();
    mover_->Display(this);

    return true;
}

// END
