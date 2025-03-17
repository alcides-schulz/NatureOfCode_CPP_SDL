#include "Example_1_10.h"

bool Example_1_10::Setup()
{
    PVector location(Width() / 2, Height() / 2);
    PVector velocity(0, 0);
    mover_ = new Mover_1_10(location, velocity);

    return true;
}

bool Example_1_10::Draw()
{
    ClearScreen();

    auto direction = PVector(MousePosition().x, MousePosition().y);
    direction.Sub(mover_->GetPosition());
    direction.Normalize();
    direction.Mult(0.2f);
    mover_->SetAcceleration(direction);

    mover_->Update();
    mover_->Show(this);

    return true;
}

// END
