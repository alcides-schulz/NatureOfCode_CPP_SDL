#include "Example_1_8.h"

bool Example_1_8::UserInit()
{
    auto location = PVector(WindowWidth() / 2, WindowHeight() / 2);
    auto velocity = PVector(0, 0);
    mover_ = new Mover_1_8(location, velocity);
    mover_->SetAcceleration(PVector(-0.001f, 0.01f));

    return true;
}

bool Example_1_8::UserRender(int elapsed_time)
{
    ClearScreen();

    mover_->Update();
    mover_->CheckEdges(this);
    mover_->Display(this);

    return true;
}

// END
