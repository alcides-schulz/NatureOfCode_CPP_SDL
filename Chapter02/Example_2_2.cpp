#include "Example_2_2.h"

bool Example_2_2::UserInit()
{
    moverA_ = new Mover_2_2(PVector(200, 30), 10);
    moverB_ = new Mover_2_2(PVector(440,30), 2);
    return true;
}

bool Example_2_2::UserRender(int elapsed_time)
{
    ClearScreen();

    PVector gravity(0, 0.1f);
    moverA_->ApplyForce(gravity);
    moverB_->ApplyForce(gravity);

    if (IsMouseButtonPressed(kMouseLeftButton)) {
        PVector wind(0.1f, 0);
        moverA_->ApplyForce(wind);
        moverB_->ApplyForce(wind);
    }

    moverA_->Update();
    moverA_->CheckEdges(this);
    moverA_->Display(this);

    moverB_->Update();
    moverB_->CheckEdges(this);
    moverB_->Display(this);

    return true;
}

// END
