#include "Example_2_1.h"

bool Example_2_1::Setup()
{
    mover_ = new Mover_2_1(PVector(Width() / 2, 30), 1);

    return true;
}

bool Example_2_1::Draw()
{
    ClearScreen();

    PVector gravity(0.0f, 0.1f);
    mover_->ApplyForce(gravity);
    if (IsMouseButtonPressed(kMouseLeftButton)) {
        PVector wind(0.1f, 0.0f);
        mover_->ApplyForce(wind);
    }

    mover_->Update();
    mover_->CheckEdges(this);
    mover_->Show(this);

    return true;
}

// END
