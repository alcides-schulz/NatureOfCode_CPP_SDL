#include "Example_2_4.h"

bool Example_2_4::Setup()
{
    mover_ = new Mover_2_4(PVector(Width() / 2, 30), 5);
    return true;
}

bool Example_2_4::Draw()
{
    ClearScreen();

    PVector gravity(0.0f, 0.1f);
    mover_->ApplyForce(gravity);

    if (IsMouseButtonPressed(kMouseLeftButton)) {
        PVector wind(0.5f, 0.0f);
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
    mover_->Show(this);

    return true;
}

// END
