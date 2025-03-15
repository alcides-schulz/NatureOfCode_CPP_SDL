#include "Example_3_10.h"

bool Example_3_10::UserInit(void)
{
    spring_ = new Spring_3_10(PVector(WindowWidth() / 2, 10), 100);
    bob_ = new Bob_3_10(PVector(WindowWidth() / 2, 100));

    return true;
}

bool Example_3_10::UserRender(int elapsed_time)
{
    ClearScreen();

    if (IsMouseButtonPressed(kMouseLeftButton))
        bob_->HandleClick(MousePosition().x, MousePosition().y);
    else
        bob_->StopDragging();

    auto gravity = PVector(0, 2);
    bob_->ApplyForce(gravity);
    bob_->Update(this);
    bob_->HandleDrag(MousePosition().x, MousePosition().y);

    spring_->Connect(bob_);
    spring_->ConstrainLength(bob_, 30, 200);
    spring_->ShowLine(this, bob_);

    bob_->Display(this);
    spring_->Display(this);

    return true;
}

// END
