#include "Example_2_1.h"

bool Example_2_1::UserInit()
{
    mover_ = new Mover_2_1(PVector(WindowWidth() / 2, 30), 1);
    return true;
}

bool Example_2_1::UserRender(int elapsed_time)
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
    mover_->Display(this);

    return true;
}

// END
