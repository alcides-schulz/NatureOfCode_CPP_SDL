#include "Example_2_4.h"

bool Example_2_4::UserInit()
{
    mover_ = new Mover_2_4(PVector(WindowWidth() / 2.0f, 30), 5);
    return true;
}

bool Example_2_4::UserRender(int elapsed_time)
{
    ClearScreen();

    PVector gravity(0, 0.1f);
    mover_->ApplyForce(gravity);

    if (IsMouseButtonPressed(kMouseLeftButton)) {
        PVector wind(0.5f, 0);
        mover_->ApplyForce(wind);
    }

    if (mover_->ContactEdge(this)) {
        float c = 0.1f;
        auto friction = mover_->GetVelocity().Clone();
        friction.Mult(-1);
        friction.SetMag(c);
        mover_->ApplyForce(friction);
    }

    mover_->BounceEdges(this);
    mover_->Update();
    mover_->Display(this);

    return true;
}

// END
