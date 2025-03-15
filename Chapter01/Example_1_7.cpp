#include "Example_1_7.h"

bool Example_1_7::Setup()
{
    auto location = PVector(rand() % Width(), rand() % Height());
    auto velocity = PVector(rand() % 5 - 2, rand() % 5 - 2);
    mover_ = new Mover_1_7(location, velocity);

    return true;
}

bool Example_1_7::Draw()
{
    ClearScreen();

    mover_->Update();
    mover_->CheckEdges(this);
    mover_->Show(this);

    return true;
}

//END
