#include "Example_2_2.h"

bool Example_2_2::Setup()
{
    moverA_ = new Mover_2_2(PVector(200, 30), 10);
    moverB_ = new Mover_2_2(PVector(440,30), 2);
    return true;
}

bool Example_2_2::Draw()
{
    ClearScreen();

    PVector gravity(0.0f, 0.1f);
    moverA_->ApplyForce(gravity);
    moverB_->ApplyForce(gravity);

    if (IsMouseButtonPressed(kMouseLeftButton)) {
        PVector wind(0.1f, 0.0f);
        moverA_->ApplyForce(wind);
        moverB_->ApplyForce(wind);
    }

    moverA_->Update();
    moverA_->CheckEdges(this);
    moverA_->Show(this);

    moverB_->Update();
    moverB_->CheckEdges(this);
    moverB_->Show(this);

    return true;
}

// END
