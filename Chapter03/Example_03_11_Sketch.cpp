#include "Example_03_11_Sketch.h"

namespace nature_of_code_chapter_03_example_11
{
    bool Sketch::Setup(void)
    {
        _pendulum = new Pendulum(Width() / 2, 0, 175);
        return true;
    }
    
    bool Sketch::Draw(void)
    {
        Background(255);
        if (IsMouseButtonHeld(kMouseLeftButton))
            _pendulum->HandleClick(MousePosition().x, MousePosition().y);
        else
            _pendulum->StopDragging();
        _pendulum->Update();
        _pendulum->Show(this);
        _pendulum->HandleDrag(MousePosition().x, MousePosition().y);
        return true;
    }
    
}

// END
