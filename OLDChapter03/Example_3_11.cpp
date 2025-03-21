#include "Example_3_11.h"

bool Example_3_11::Setup(void)
{
    pendulum_ = new Pendulum_3_11(Width() / 2, 0, 175);
    return true;
}

bool Example_3_11::Draw(void)
{
    ClearScreen();
    if (IsMouseButtonHeld(kMouseLeftButton))
        pendulum_->HandleClick(MousePosition().x, MousePosition().y);
    else
        pendulum_->StopDragging();
    pendulum_->Update();
    pendulum_->Show(this);
    pendulum_->HandleDrag(MousePosition().x, MousePosition().y);
    return true;
}

// END
