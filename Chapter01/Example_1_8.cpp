#include "Example_1_8.h"

bool Example_1_8::Setup()
{
    auto location = PVector(Width() / 2, Height() / 2);
    auto velocity = PVector(0, 0);
    mover_ = new Mover_1_8(location, velocity);
    mover_->SetAcceleration(PVector(-0.001f, 0.01f));

    return true;
}

bool Example_1_8::Draw()
{
    ClearScreen();

    mover_->Update();
    mover_->CheckEdges(this);
    mover_->Show(this);

    return true;
}

// END
