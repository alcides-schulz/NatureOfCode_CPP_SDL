#include "Example_1_9.h"

bool Example_1_9::Setup()
{
    PVector location((float)(Width() / 2), (float)(Height() / 2));
    PVector velocity(0, 0);
    mover_ = new Mover_1_9(location, velocity);
    return true;
}

bool Example_1_9::Draw()
{
    ClearScreen();

    mover_->Update();
    mover_->CheckEdges(this);
    mover_->Show(this);

    return true;
}

// END
