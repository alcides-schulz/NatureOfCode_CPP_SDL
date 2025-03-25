#include "Example_03_11_Sketch.h"

namespace nature_of_code_chapter_03_example_11
{
    bool Sketch::Setup(void)
    {
        pendulum_ = new Pendulum(Width() / 2, 0, 175);
        return true;
    }
    
    bool Sketch::Draw(void)
    {
        Background(255);
        if (IsMouseButtonHeld(kMouseLeftButton))
            pendulum_->HandleClick(MousePosition().x, MousePosition().y);
        else
            pendulum_->StopDragging();
        pendulum_->Update();
        pendulum_->Show(this);
        pendulum_->HandleDrag(MousePosition().x, MousePosition().y);
        return true;
    }
    
}

// END
