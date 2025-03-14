#include "Example_3_3.h"

bool Example_3_3::UserInit(void)
{
    mover_ = new Mover_3_3(PVector(WindowWidth() / 2, WindowHeight() / 2));

    auto x = PVector(100, 50).Heading();
    cout << x << endl;

    return true;
}

bool Example_3_3::UserRender(int elapsed_time)
{
    ClearScreen();

    mover_->Update(this);
    mover_->CheckEdges(this);
    mover_->Display(this);

    return true;
}

// END
