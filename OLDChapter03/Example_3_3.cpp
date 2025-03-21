#include "Example_3_3.h"

bool Example_3_3::Setup(void)
{
    mover_ = new Mover_3_3(PVector(Width() / 2, Height() / 2));

    auto x = PVector(100, 50).Heading();
    cout << x << endl;

    return true;
}

bool Example_3_3::Draw()
{
    ClearScreen();

    mover_->Update(this);
    mover_->CheckEdges(this);
    mover_->Show(this);

    return true;
}

// END
