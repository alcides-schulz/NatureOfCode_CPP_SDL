#include "Example_02_01_Sketch.h"

namespace nature_of_code_chapter_02_example_01
{
    bool Sketch::Setup()
    {
        _mover = new Mover(Vector(Width() / 2, 30), 1);
    
        return true;
    }
    
    bool Sketch::Draw()
    {
        Background(255);
    
        Vector gravity(0.0f, 0.1f);
        _mover->ApplyForce(gravity);
        if (IsMouseButtonHeld(kMouseLeftButton)) {
            Vector wind(0.1f, 0.0f);
            _mover->ApplyForce(wind);
        }
    
        _mover->Update();
        _mover->CheckEdges(this);
        _mover->Show(this);
    
        return true;
    }
    
}

// END
