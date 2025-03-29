#include "Example_03_10_Sketch.h"

namespace nature_of_code_chapter_03_example_10
{
    bool Sketch::Setup(void)
    {
        _spring = new Spring(Vector(Width() / 2, 10), 100);
        _bob = new Bob(Vector(Width() / 2, 100));
    
        return true;
    }
    
    bool Sketch::Draw()
    {
        Background(255);
    
        if (IsMouseButtonHeld(kMouseLeftButton))
            _bob->HandleClick(MousePosition().x, MousePosition().y);
        else
            _bob->StopDragging();
    
        auto gravity = Vector(0, 2);
        _bob->ApplyForce(gravity);
        _bob->Update(this);
        _bob->HandleDrag(MousePosition().x, MousePosition().y);
    
        _spring->Connect(_bob);
        _spring->ConstrainLength(_bob, 30, 200);
        _spring->ShowLine(this, _bob);
    
        _bob->Show(this);
        _spring->Show(this);
    
        return true;
    }
    
}

// END
