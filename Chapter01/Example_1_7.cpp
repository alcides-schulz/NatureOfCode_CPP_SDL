#include "Example_1_7.h"

bool Example_1_7::UserInit()
{
    auto location = PVector(rand() % WindowWidth(), rand() % WindowHeight());
    auto velocity = PVector(rand() % 5 - 2, rand() % 5 - 2);
    mover_ = new Mover_1_7(location, velocity);

    return true;
}

bool Example_1_7::UserRender(int elapsed_time)
{
    ClearScreen();

    mover_->Update();
    mover_->CheckEdges(this);
    mover_->Display(this);

    return true;
}

//END
