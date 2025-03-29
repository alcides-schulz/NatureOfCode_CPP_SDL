#include "Example_02_02_Sketch.h"

namespace nature_of_code_chapter_02_example_02
{
    bool Sketch::Setup()
    {
        _moverA = new Mover(Vector(200, 30), 8);
        _moverB = new Mover(Vector(440, 30), 2);
        return true;
    }
    
    bool Sketch::Draw()
    {
        Background(255);
    
        Vector gravity(0.0f, 0.1f);
        _moverA->ApplyForce(gravity);
        _moverB->ApplyForce(gravity);
    
        if (IsMouseButtonHeld(kMouseLeftButton)) {
            Vector wind(0.1f, 0.0f);
            _moverA->ApplyForce(wind);
            _moverB->ApplyForce(wind);
        }
    
        _moverA->Update();
        _moverA->CheckEdges(this);
        _moverA->Show(this);
    
        _moverB->Update();
        _moverB->CheckEdges(this);
        _moverB->Show(this);
    
        return true;
    }
    
}

// END
